### Program for effective and optimized traffic light management. Carried out as part of mentoring.

### START

1) git clone https://github.com/kuriataz/traffic-lights.git
2) cd traffic-lights
3) cmake -GNinja -Bbuild
4) ninja -Cbuild
5) ./build/main (--input <input_file.txt> | -i <input_file.txt>) (--output <output_file.txt> | -o <output_file.txt>) [--detail | -d]



### INPUT:

For every direction (N, E, S, W) in separate line probabilty that the car will go from that
direction  in a specific direction from the ones that are left (0.0 <= sum <= 1.0).

One line free.

For every crossing (N, E, S, W) probabilty that a pedestrian will want to cross the street.

[from N going S] [from N going E] [from N going W]
[from E going W] [from E going S] [from E going N]
[from S going N] [from S going W] [from S going E]
[from W going E] [from W going N] [from W going S]

[N crossing] [E crossing] [S crossing] [W crossing]


Example input file:

0.12 0.1 0.15
0.20 0.17 0.16
0.02 0.31 0.12
0.02 0.11 0.13

0.5 0.3 0.2 0.8
