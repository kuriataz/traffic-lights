### Program for effective and optimized traffic light management. Carried out as part of mentoring.

### START

1) git clone https://github.com/kuriataz/traffic-lights.git
2) cd traffic-lights
3) cmake -GNinja -Bbuild
4) ninja -Cbuild
5) ./build/main (--input <input_file.txt> | -i <input_file.txt>) (--output <output_file.txt> | -o <output_file.txt>) [--detail | -d]

    EXAMPLE RUN: ./build/main --input example/input.txt --output ex.txt -d

    The output should be the same as in examples/output_detail.txt



### CLASS DIAGRAM

![alt text](https://github.com/kuriataz/traffic-lights/blob/main/docs/class_diagram.png)

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
