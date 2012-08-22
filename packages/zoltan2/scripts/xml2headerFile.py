#!/usr/bin/python

# place a backslash before double quotes
esc = "\\"
quo = '"'
escquo = esc+quo

def addLine(line, f):
  line = line.strip()
  if '"' in line:
    parts = line.split('"')
    line = escquo.join(parts)
  ln = 'xmlParameterDef.append("' + line + '");\n'
  f.write(ln)
  

hppFile = open("Zoltan2_XML_Parameters.hpp", "w")

# The copyright

cFile = open("copyright.txt", "r")
heading = cFile.read()
hppFile.write(heading)
cFile.close()

# The comment

hppFile.write("// \n")
hppFile.write("// This file is automatically generated by a script\n")
hppFile.write("// at compile time that processes parameters.xml.\n")
hppFile.write("// \n")

hppFile.write("#ifndef ZOLTAN2_XML_PARAMETERS_HPP\n")
hppFile.write("#define ZOLTAN2_XML_PARAMETERS_HPP\n")

# The parameters

hppFile.write("std::string xmlParameterDef;\n")

paramFile = open("../data/parameters.xml", "r")

for line in paramFile:
  if "ParameterList" in line:
    addLine(line, hppFile)
    break

for line in paramFile:
  if len(line) > 2:
    addLine(line, hppFile)
  if "/ParameterList" in line:
    break


hppFile.write("#endif   // ZOLTAN2_XML_PARAMETERS_HPP\n")

hppFile.close()
paramFile.close()


