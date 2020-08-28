## Core Utils Recreation

This is a simple project in which I attempt to recreate the GNU core utilities.
 In order to keep myself fresh while working from home, I have decided to take a deep dive into the UNIX shell utilities (technically the GNU core utils).
I am recreating them in no particular order (read: whatever seems easiest first) to help myself better understand C and this sort of development.
The way I am planning on going about this is pretty simple, I pick a utility, run 'man [utility]' and see if I can replicate the functionality myself.
There are a few caveats, I am allowing myself to use system libraries, unless the functionality is interesting or novel (read: I passed university, I can
write strcmp and I don't feel like doing that every project, an example of interesting functionality would be argument parsing). Also, I am going to do 
my best to keep things in single modules instead of splitting them up into
libraries, this is just so I can get really get a feel for ** all **  the 
moving parts of each utility (this is why I will be using system libraries for things like strcmp). Finally, everything will be compiled with clang, not GCC. I don't
have any particular reason for this other than I like clang.


 Every utility I do will have three stages. The first stage I will implement the simplest version I can of the utility. This means base functionality only, no flags,
just whatever the core feature is (example, for the first stage of 'cat' I only do stdin echoing and file output). The second stage I will attempt to implement all of
the options and flags of the command. The final stage I will compare my produced code with the source code from the GNU source utils, and write up the differences. Each 
stage will have its own write up, so that I can reflect on what I did, why, and perhaps correct my mistakes. I hope that this project will be beneficial to me in the long
run, allowing me to grow as a programmer, as well as giving me some practical experience before jumping into contributing to open source projects like suckless software, or
maybe even eventually contributing to linux kernel code.
