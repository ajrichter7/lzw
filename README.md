# LZW Implememtation in C++ 
## Alex Richter, Ariel Flaster



### to run this, do 
`make ass`


then do 
`./lz [filename]`
I forgot what the name of the executable is, but we'll figure it out :)

##Compression
Start by constructing the table  with the ASCII characters in the first 256 entries. Get the first character and then since it with is only a single character it is in the table so we want to see if that plus the next character is in the 
table which it is not, so then we are going to add that to the new table and increment the size of the table. Note that newcode is a counter to make sure that we don’t go past the number of possible substrings. If we reach that condition, then we want to just encode the text using the values in the table and stop expanding the table. The encoded sequence is then outputted to file. 

##Decompression
Build the same dictionary and then we want to search through the dictionary to find the characters. This function will read in an encoded file and then we will write a decompressed version. 
We read in the first value which is a number in ASCII so we look it up in the table we have created. Then we go and check if the next character can be read. If it is a value greater than the table size, then we are going 
to want to add the new value as an entry of the old code + new character. We want to output the string to the output file. 


The compressed file will have the extension `WE_LOVE_CS_421`

The compression and decompression algorithms both successfully were used on DAVID COPPERFIELD, which is Ariel's favorite book!

