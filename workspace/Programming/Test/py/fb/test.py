#!/usr/bin/python3

def check(serverName):
    fb = open("services.csv","r")
    lines = fb.readlines()
    computeReq = dict()
    index = 1
    for line in lines:
        if (index != 1):
            dtype = line.split(",")[1]
            dcap = line.split(",")[2]
            if (dtype in computeReq):
                computeReq[dtype] += int(dcap)
            else:
                computeReq[dtype] = int(dcap)
        index += 1
    fb.close()

    fb = open("dc.csv", "r")
    lines = fb.readlines()
    index = 1
    for line in lines:
        if (index != 1):
            s = line.split(",")[0]
            if (s != serverName):
                dtype = line.split(',')[1]
                dcap = line.split(",")[2]
                print ("server %s [%s] = %d - %d .. " %(s, dtype, computeReq[dtype], int(dcap)))
                computeReq[dtype] -= int(dcap)
                print ("updated need as [%s] = %d\n" %(dtype, computeReq[dtype]))
        index += 1
    fb.close()

    for key,value in computeReq.items():
        if (value > 0):
            print ("Insufficient compute for %s - %d\n" %(key, value))
            return 0
        else:
            print ("Sufficient for compute %s - %d\n" %(key, value))

    return 1


check("NORTH_AMERICA_01")
