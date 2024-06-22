import subprocess


def run():
    fn = "results"
    count = 0
    while True:
        try:
            count += 1
            basic_filename = fn + str(count) + ".txt"
            temp_filename = "temp_"+fn + str(count) + ".txt"
            final_filename = "final_"+fn + str(count) + ".txt"
            finalfinal_filename = "finalfinal_"+fn + str(count) + ".txt"
            #define all of our file names
            temp = open(basic_filename, "r")
            cmd = "./script.sh " + basic_filename + " " + temp_filename + " " + final_filename + " " + finalfinal_filename # generate our 1-liner
            subprocess.call(cmd, shell=True) # run it


        except Exception:
            break
