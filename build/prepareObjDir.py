import os
import os.path
#
# (C) Copytight 2017 Marek Bielawski
# copyDirs
#

def copyDirs(root):
   inDir = '../code/' + root 
   outDir = 'obj/' + root
   if inDir[len(inDir)-1] != '/':
       inDir += '/'
   if outDir[len(outDir)-1] != '/':
       outDir += '/'
   inFiles = os.listdir(inDir)
   for inFile in inFiles:
       inPath = inDir + inFile
       if os.path.isdir(inPath):
          outPath = inPath.replace(inDir, outDir)
          if not os.path.isdir(outPath) :
            print outPath + ' missing. Creating Dir'
            os.mkdir(outPath)
          copyDirs(inPath)
copyDirs('')
