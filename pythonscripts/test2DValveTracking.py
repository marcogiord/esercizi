import sys
import copy
import shutil
import os
import subprocess
import re
import numpy as np


input="F:/projects/2DValveTracking"
par_dir="F:/projects/LKEB_contour_registration/scripts"
result_dir=input
itktoolsdir="F:/projects/LKEB_contour_registration/scripts/tools/bin/bin/Debug"
pxcastbin=itktoolsdir+"/pxcastconvert.exe"
elastixbin="C:/code/tools/elastix_v4.7/elastix.exe"
transformix="C:/code/tools/elastix_v4.7/transformix.exe"
combinepy = par_dir + "/combine.py"
#contour_file = "F:/projects/LKEB_contour_registration/data/testContour"

def run_registration(outputdir):
    #outputdir = result_dir + "/result/"
    if not os.path.exists(outputdir):
        os.makedirs(outputdir)
    # run elastix # # create moving/atlas image string
    image_file = input + "/testDataset2Ch.mhd"
    process = subprocess.Popen([elastixbin,'-threads',str(8),'-f', image_file, '-m', image_file, '-out', outputdir,
                                '-p', par_dir + "/par000.forward.txt", '-p',
         par_dir + "/par000.inverse.txt"])
    stdout, stderr = process.communicate()
    # convert
    process = subprocess.Popen([pxcastbin, '-in', outputdir + "result.0.mhd", '-out', outputdir + "fwd.mhd"])
    stdout, stderr = process.communicate()
    process = subprocess.Popen([pxcastbin, '-in', outputdir + "result.1.mhd", '-out', outputdir + "inv.mhd"])
    stdout, stderr = process.communicate()

def find_index_frame(inputdir):
    index_frame = 0
    file_reference = ''
    for file in os.listdir(inputdir):
       if file.startswith('valve'):
           print("current file is:" + file)
           s = re.findall(r"[-+]?\d*\.\d+|\d+", file)
           index_frame = s[0]
           # print(index_frame)
           file_reference = inputdir + '/' + file
    return index_frame, file_reference

def combine(index_frame, outputdir):
    transform_file0 = outputdir + "TransformParameters.0.txt"
    transform_file1 = outputdir + "TransformParameters.1.txt"
    combine_file0 = outputdir + "Combined.0.txt"
    combine_file1 = outputdir + "Combined.1.txt"
    # combine transformation
    cmd = 'python ' + combinepy + ' point ' + transform_file0 + ' ' + transform_file1 + ' ' + combine_file0 + ' ' \
          + combine_file1 + ' ' + str(index_frame)
    print(cmd)
    process = subprocess.Popen(cmd)
    stdout, stderr = process.communicate()

def post_processing(outputdir, nr_frames):
    #outputdir = result_dir + "/slice" + str(slice)
    index_frame, file_reference = find_index_frame(outputdir)
    for p in range(0, nr_frames):  # loop over all frames
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
        process = subprocess.Popen([transformix, '-tp', outputdir + "Combined.1.txt", '-def', file_replicated_end,
                                    '-out', outputdir])
        stdout, stderr = process.communicate()
        # read output points file
        file_output = outputdir + "outputpoints.txt"
        # create final point file
        file_output_final = outputdir + "pointendt" + str(p) + ".txt"
        with open(file_output_final, 'w') as output_final:
            with open(file_output, 'r') as output_points:
                for line in output_points:
                    d = line.split(';')
                    # print(d[4])
                    f = d[4]
                    s = re.findall(r"[-+]?\d*\.\d+|\d+", f)
                    #s[2] = 0.5
                    s.append(p)
                    output_final.write("{0} {1} {2}\n".format(*s))


def main():
    # do the registration in the background
    outputdir = result_dir + "/result3/"
    run_registration(outputdir)
    # find index frame
    index_frame, reference_file = find_index_frame(outputdir)
    #print(reference_file)
    # combine transformations
    combine(index_frame, outputdir)
    # transformations
    post_processing(outputdir, 25)

if __name__ == "__main__":
    main()

