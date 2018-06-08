import sys
import copy
import shutil
import os
import subprocess
import re
import numpy as np


input="F:/projects/LKEB_contour_registration/data/AF_27_m_48"
par_dir="F:/projects/LKEB_contour_registration/scripts"
result_dir=input 
itktoolsdir="F:/projects/LKEB_contour_registration/scripts/tools/bin/bin/Debug"
pxcastbin=itktoolsdir+"/pxcastconvert.exe"
elastixbin="C:/code/tools/elastix_v4.7/elastix.exe"
transformix="C:/code/tools/elastix_v4.7/transformix.exe"
combinepy = par_dir + "/combine.py"
contour_file = "F:/projects/LKEB_contour_registration/data/testContour"


def find_index_frame(inputdir):
    index_frame = 0
    file_reference = ''
    for file in os.listdir(inputdir):
        if file.startswith('end'):
            print("current file is:" + file)
            s = re.findall(r"[-+]?\d*\.\d+|\d+", file)
            index_frame = s[0]
            #print(index_frame)
            file_reference = inputdir + '/' + file
    return index_frame, file_reference

def run_registration(slice):
    outputdir = result_dir + "/slice" + str(slice)
    if not os.path.exists(outputdir):
        os.makedirs(outputdir)
    # run elastix # # create moving/atlas image string
    image_file = input + "/4D_" + str(slice) + ".mhd"
    process = subprocess.Popen([elastixbin, '-f', image_file, '-m', image_file, '-out', outputdir, '-p', par_dir + "/par000.forward.txt", '-p',
         par_dir + "/par000.inverse.txt"])
    stdout, stderr = process.communicate()
    # convert
    process = subprocess.Popen([pxcastbin, '-in', outputdir + "/result.0.mhd", '-out', outputdir + "/slice" + str(slice) + "fwd.mhd"])
    stdout, stderr = process.communicate()
    process = subprocess.Popen([pxcastbin, '-in', outputdir + "/result.1.mhd", '-out', outputdir + "/slice" + str(slice) + "inv.mhd"])
    stdout, stderr = process.communicate()

def read_qmap_contour_file(file):
    slice_interval = [0, 1, 2]
    contour_dict = {}

    # Find [XYCONOUTR]
    contour_key = next_line
    points = contour_dict.setdefault(contour_key, [])
    if points:
        print('Warning already found points with key', contour_key)

    # empty list for the new contour
    #points = []

    # in loop over points
    points.append([2 , 34 , 45, 34])
    # etc...

    #contour_dict[contour_key] = points

    # with open(file_output, 'r') as inputfile:
    #     for line in inputfile:
    #         if line.startswith([XYCONTOUR]): # new contour is found
    #             next(line)
    #             print(newline)

# performs elastix group-wise registration an dcretaes direct/inverse transformations
def pre_processing(slice_interval):
    for slice in slice_interval:
        print("running preprocessing on slice nr " + str(slice))
        outputdir = result_dir + "/slice" + str(slice)
        run_registration(slice)
        # find index frame
        index_frame, file_reference = find_index_frame(outputdir)
        transform_file0 = outputdir + "/TransformParameters.0.txt"
        transform_file1 = outputdir + "/TransformParameters.1.txt"
        combine_file0 = outputdir + "/Combined.0.txt"
        combine_file1 = outputdir + "/Combined.1.txt"
        # combine transformation
        cmd = 'python ' + combinepy + ' point ' + transform_file0 + ' ' + transform_file1 + ' ' + combine_file0 + ' ' + combine_file1 + ' ' + str(index_frame)
        process = subprocess.Popen(cmd)
        stdout, stderr = process.communicate()

# performs the transformation on the contour file
def post_processing(slice_interval):
    for slice in slice_interval:
        outputdir = result_dir + "/slice" + str(slice)
        index_frame, file_reference = find_index_frame(outputdir)
        for p in range(0, 150):  # loop over all frames
            file_replicated_end = outputdir + '/' + 'pointend' + str(p) + '.txt'
            with open(file_replicated_end, 'w') as replica:
                with open(file_reference, 'r') as input:
                    line = input.readline()  # read 'point' text
                    replica.write(line)
                    line = input.readline()  # read nr of points
                    replica.write(line)
                    nr_points = line.split()[0]
                    for i in range(0, int(nr_points)):
                        line = input.readline()
                        s = line.split()
                        s[2] = p  # set current frame
                        replica.write("{0} {1} {2}\n".format(*s))
            # call trasformix
            process = subprocess.Popen([transformix, '-tp', outputdir + "/Combined.1.txt", '-def', file_replicated_end, '-out', outputdir])
            stdout, stderr = process.communicate()
            # read output points file
            file_output = outputdir + "/outputpoints.txt"
            # create final point file
            file_output_final = outputdir + "/pointendt" + str(p) + ".txt"
            with open(file_output_final, 'w') as output_final:
                with open(file_output, 'r') as output_points:
                    for line in output_points:
                        d = line.split(';')
                        # print(d[4])
                        f = d[4]
                        s = re.findall(r"[-+]?\d*\.\d+|\d+", f)
                        s[2] = 0.5
                        s.append(p)
                        output_final.write("{0} {1} {2} {3}\n".format(*s))
        # create file with z= 0.5 and frame number
        # for fname in os.listdir(outputdir):
        #    if fname.startswith("point"):
        #        os.remove(os.path.join(outputdir, fname))

def main():
    interval = [18]
    nr_args = len(sys.argv)
    list_processings = list()
    read_qmap_contour_file(contour_file)
    #sys.exit()
    # skip file name and get all arguments
    for i in range(1, nr_args):
        s = sys.argv[i]
        if s == "preprocessing" or s == "postprocessing":
            list_processings.append(s)
        else:
            print("wrong processing invoked " +s)
    # launch the processings
    for s in list_processings:
        if s == "preprocessing":
            print("running pre_processing")
            pre_processing(interval)
        if s == "postprocessing":
            post_processing(interval)
#    for slice in interval:
#       outputdir = result_dir + "/slice" + str(slice)
#       run_registration(slice)
#       # find index frame
#       index_frame, file_reference = find_index_frame(outputdir)
#       transform_file0 = outputdir + "/TransformParameters.0.txt"
#       transform_file1 = outputdir + "/TransformParameters.1.txt"
#       combine_file0 = outputdir + "/Combined.0.txt"
#       combine_file1 = outputdir + "/Combined.1.txt"
#       # combine transformation
#       cmd = 'python ' + combinepy + ' point ' + transform_file0 + ' ' + transform_file1 + ' ' + combine_file0 + ' ' + combine_file1 + ' ' + str(index_frame)
#       process = subprocess.Popen(cmd)
#       stdout, stderr = process.communicate()


if __name__ == "__main__":
    main()
    #read_qmap_contour_file(f:\projects\LKEB_contour_registration\data\)