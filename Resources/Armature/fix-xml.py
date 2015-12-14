import xml.etree.ElementTree as et
from os import listdir
from os.path import isfile, join
files = [f for f in listdir(
    './') if isfile(join('./', f)) and f.endswith('xml')]
for xml_file in files:
    print xml_file
    tree = et.parse(xml_file)
    root = tree.getroot()
    for b in root.iter('b'):
        prev = None
        for f in b:
            if (
                    prev is not None
                    and 'z' not in f.attrib
                    and 'dI' in f.attrib
                    and f.attrib['dI'] == '-1'
                    and 'dI' in prev.attrib
                    and prev.attrib['dI'] != '-1'
            ):
                print prev.attrib
                print f.attrib
                print '---------------------'
                for a in prev.attrib:
                    if a not in f.attrib:
                        f.attrib[a] = prev.attrib[a]
            if (
                    prev is not None
                    and 'z' not in prev.attrib
                    and 'dI' in prev.attrib
                    and prev.attrib['dI'] == '-1'
                    and 'dI' in f.attrib
                    and f.attrib['dI'] != '-1'
            ):
                print prev.attrib
                print f.attrib
                print '---------------------'
                for a in f.attrib:
                    if a not in prev.attrib:
                        prev.attrib[a] = f.attrib[a]
            prev = f
    print
    tree.write(xml_file)
