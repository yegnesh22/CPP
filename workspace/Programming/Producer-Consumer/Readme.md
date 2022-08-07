Simple Producer-Consumer simulation
-----------------------------------
1. Event - User input
2. Write event - can take 1 argument size, as the user input. size should be between (1-4).
   Reads size * 4 bytes of data from the input file and writes to the queue.
3. Read event - Default read writes 2 slots (8 bytes from the queue and writes it to the output
   file.
4. Rate limit - If the queue is full, 4 slots (4 * 4 bytes = 16 bytes) are freed from the dataQ
   and written to the output file.

Source
------
PC.cpp - source file
input.txt - sample input file

Compiling
---------
Run 'make' from this directory. This will create executable 'PC' in this directory.

Executing
---------
Run the command ./PC.
Keep feeding the events (r - for read, and w - for write). For write event user input expected
for write size as well.
