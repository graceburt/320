Read Me Project 2

What we want: 


1. Holy heck it is very confusing. SO Dictionary is the hash class which holds the actual hash table, and Node is the word class. Node is essentially a doubly linked list, which I probably could have used more efficiently to print/search through the hash, but I didn't. Insertion works similary to a linked list insert, so does search. 
spellCheck() is the only unique function, which is the one edit distance function. It goes through the entire alphabet looking for words that are editable (if the word is not in the already read in dictionary i.e. "misspelled") and displays the new words to the user. 
2. The dictionary was STUPID. I couldn't tell what was actually misspelled or if it was just the dumb dictionary.
3. The keys are the hashes themselves, and the word is the string before hash. 
5. My hash is the same from the lab, using multiplication way. Then imput that into the doubly linked list hash table data.

TESTING:


grace@Grace-Ubuntu:~/Documents/COSC320/Proj/proj2burton$ make
g++ -c -std=c++11 main.cpp -g
g++ -std=c++11 main.o -o main
grace@Grace-Ubuntu:~/Documents/COSC320/Proj/proj2burton$ ./main
File is inputting...
Insertion of file into hash took: 6247.35 miliseconds
--------------------------------------
Total # of words in Hash:  | 466545
--------------------------------------
Total # of buckets in Hash:  | 8192
--------------------------------------
Total # of buckets in use:  | 1063
--------------------------------------
--------------------------------------
Largest bucket size:  | 7869
--------------------------------------
Average bucket size:  | 5530.88
--------------------------------------
Smallest bucket size:  | 19
--------------------------------------
Please enter a sentence: 
my
You entered: my
m
run 0 
y
run 1 m

run 2 my
my is not a word in this dictionary, finding suggestions...
Can be replaced with: ay
Can be replaced with: by
Can be replaced with: cy
Can be replaced with: dy
Can be replaced with: ey
Can be replaced with: fy
Can be replaced with: gy
Can be replaced with: hy
Can be replaced with: iy
Can be replaced with: ky
Can be replaced with: ly
Can be replaced with: my
Can be replaced with: ny
Can be replaced with: oy
Can be replaced with: py
Can be replaced with: qy
Can be replaced with: ry
Can be replaced with: sy
Can be replaced with: ty
Can be replaced with: uy
Can be replaced with: vy
Can be replaced with: wy
Can be replaced with: yy
Can be replaced with: xy
Can be replaced with: zy
Can be replaced with: y
Can be replaced with: ma
Can be replaced with: mb
Can be replaced with: mc
Can be replaced with: md
Can be replaced with: me
Can be replaced with: mf
Can be replaced with: mg
Can be replaced with: mh
Can be replaced with: mi
Can be replaced with: mk
Can be replaced with: ml
Can be replaced with: mm
Can be replaced with: mn
Can be replaced with: mo
Can be replaced with: mp
Can be replaced with: mq
Can be replaced with: mr
Can be replaced with: ms
Can be replaced with: mt
Can be replaced with: mu
Can be replaced with: mv
Can be replaced with: mw
Can be replaced with: my
Can be replaced with: mx
Can be replaced with: mz
Can be replaced with: m
Can be replaced with: mya
Can be replaced with: myb
Can be replaced with: myc
In dictionary! 
Can be replaced with: myd
Can be replaced with: mye
Can be replaced with: myf
Can be replaced with: myg
In dictionary! 
Can be replaced with: myh
Can be replaced with: myi
Can be replaced with: myk
Can be replaced with: myl
Can be replaced with: mym
In dictionary! 
Can be replaced with: myn
Can be replaced with: myo
Can be replaced with: myp
Can be replaced with: myq
Can be replaced with: myr
Can be replaced with: mys
Can be replaced with: myt
Can be replaced with: myu
Can be replaced with: myv
Can be replaced with: myw
Can be replaced with: myy
Can be replaced with: myx
Can be replaced with: myz
Can be replaced with: my
--------------------------------------
Time to compute suggestions:  | 23.3667
--------------------------------------
Number of incorrect words:  | 1
--------------------------------------
Number of possible words:  | 78
--------------------------------------
grace@Grace-Ubuntu:~/Documents/COSC320/Proj/proj2burton$ ./main
File is inputting...
Insertion of file into hash took: 6732.1 miliseconds
--------------------------------------
Total # of words in Hash:  | 466545
--------------------------------------
Total # of buckets in Hash:  | 8192
--------------------------------------
Total # of buckets in use:  | 1063
--------------------------------------
--------------------------------------
Largest bucket size:  | 7869
--------------------------------------
Average bucket size:  | 5530.88
--------------------------------------
Smallest bucket size:  | 19
--------------------------------------
Please enter a sentence: 
hell
You entered: hell
h
run 0 
e
run 1 h
l
run 2 he
l
run 3 hel

run 4 hell
hell is not a word in this dictionary, finding suggestions...
Can be replaced with: aell
Can be replaced with: bell
Can be replaced with: cell
Can be replaced with: dell
Can be replaced with: eell
Can be replaced with: fell
Can be replaced with: gell
Can be replaced with: hell
Can be replaced with: iell
Can be replaced with: kell
Can be replaced with: lell
Can be replaced with: mell
Can be replaced with: nell
Can be replaced with: oell
Can be replaced with: pell
Can be replaced with: qell
Can be replaced with: rell
Can be replaced with: sell
Can be replaced with: tell
Can be replaced with: uell
Can be replaced with: vell
Can be replaced with: well
Can be replaced with: yell
Can be replaced with: xell
Can be replaced with: zell
Can be replaced with: ell
Can be replaced with: hall
Can be replaced with: hbll
Can be replaced with: hcll
Can be replaced with: hdll
Can be replaced with: hell
Can be replaced with: hfll
Can be replaced with: hgll
Can be replaced with: hhll
Can be replaced with: hill
Can be replaced with: hkll
Can be replaced with: hlll
Can be replaced with: hmll
Can be replaced with: hnll
Can be replaced with: holl
Can be replaced with: hpll
Can be replaced with: hqll
Can be replaced with: hrll
Can be replaced with: hsll
Can be replaced with: htll
Can be replaced with: hull
Can be replaced with: hvll
Can be replaced with: hwll
Can be replaced with: hyll
Can be replaced with: hxll
Can be replaced with: hzll
Can be replaced with: hll
Can be replaced with: heal
Can be replaced with: hebl
Can be replaced with: hecl
Can be replaced with: hedl
Can be replaced with: heel
Can be replaced with: hefl
Can be replaced with: hegl
Can be replaced with: hehl
Can be replaced with: heil
Can be replaced with: hekl
Can be replaced with: hell
Can be replaced with: heml
Can be replaced with: henl
Can be replaced with: heol
Can be replaced with: hepl
Can be replaced with: heql
Can be replaced with: herl
Can be replaced with: hesl
Can be replaced with: hetl
Can be replaced with: heul
Can be replaced with: hevl
Can be replaced with: hewl
Can be replaced with: heyl
Can be replaced with: hexl
Can be replaced with: hezl
Can be replaced with: hel
Can be replaced with: hela
Can be replaced with: helb
Can be replaced with: helc
Can be replaced with: held
Can be replaced with: hele
Can be replaced with: helf
Can be replaced with: helg
Can be replaced with: helh
Can be replaced with: heli
Can be replaced with: helk
Can be replaced with: hell
Can be replaced with: helm
Can be replaced with: heln
Can be replaced with: helo
Can be replaced with: help
Can be replaced with: helq
Can be replaced with: helr
Can be replaced with: hels
Can be replaced with: helt
Can be replaced with: helu
Can be replaced with: helv
Can be replaced with: helw
Can be replaced with: hely
Can be replaced with: helx
Can be replaced with: helz
Can be replaced with: hel
Can be replaced with: hella
Can be replaced with: hellb
Can be replaced with: hellc
Can be replaced with: helld
Can be replaced with: helle
Can be replaced with: hellf
Can be replaced with: hellg
Can be replaced with: hellh
Can be replaced with: helli
Can be replaced with: hellk
Can be replaced with: helll
Can be replaced with: hellm
Can be replaced with: helln
Can be replaced with: hello
In dictionary! 
Can be replaced with: hellp
Can be replaced with: hellq
Can be replaced with: hellr
Can be replaced with: hells
In dictionary! 
Can be replaced with: hellt
Can be replaced with: hellu
Can be replaced with: hellv
Can be replaced with: hellw
Can be replaced with: helly
In dictionary! 
Can be replaced with: hellx
Can be replaced with: hellz
Can be replaced with: hell
--------------------------------------
Time to compute suggestions:  | 563.417
--------------------------------------
Number of incorrect words:  | 1
--------------------------------------
Number of possible words:  | 130
--------------------------------------

