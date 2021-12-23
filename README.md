# data-structure-xml-project

## Features:

A complete xml GUI project that has the following features:

1- Load an xml file with extension ".xml"

2- Load a compressed xml file with extension ".cxml"

3- Check syntax of the input xml ('<' and '>' brackets), and outputs the error found along with its line and column

4- Check consistency of xml tags and correct them to output a valid xml file, it outputs the error found along with its line and column

5- Minify the input xml file

6- Prettify the input xml file

7- Convert any xml file to json " prettified and valid json, that has the ability to detect similar xml tags in the same level with the same names and put them in an array in json format, as repeated object names are not valid in json unlike xml"

8- Compress the xml file using Huffman's tree method, it was tested using a big file of about 643 KB and the output was 428KB, about 66% of the original file, The efficiency increases by increasing the file size and by using repeated characters. The compressed xml file is saved in a new extension ".cxml"

9- Decompressing the output ".cxml" file to obtain the original file again.

10- The ability to save the output file of all the previous operations in one of the following appropriate extensions ".json, .xml, .cxml"
