
Generating data 

```
./find.py gen 15000 4000 > data 
``` 

Compile the program 

```
g++ finder.cpp -o ./finder
```

Run Benchmarks **mitigations=off** for `C++`

```
cat data | ./finder count 33000 10000
Number of matching entries = 150000000. Time taken = 0.168351s

cat data | ./finder count 33000 10000
Number of matching entries = 150000000. Time taken = 0.169054s

cat data | ./finder count 2000 10000
Number of matching entries = 74950000. Time taken = 0.670376s

cat data | ./finder count 2000 10000
Number of matching entries = 74950000. Time taken = 0.666298s
```

Run Benchmarks **mitigations=off** for `Python`

```
cat data | ./find.py count 200000 10000
Number of matching entries = 15000. Time taken = 0.0005364418029785156

cat data | ./find.py count 200000 10000
Number of matching entries = 15000. Time taken = 0.0005676746368408203

cat data | ./find.py count 2000 10000
Number of matching entries = 7495.  Time taken = 0.0004611015319824219

cat data | ./find.py count 2000 10000
Number of matching entries = 7495.  Time taken = 0.00046133995056152344
```

Run Benchmarks **mitigations=on** for `C++`

```
cat data | ./finder count 33000 10000
Number of matching entries = 150000000. Time taken = 0.16958s

cat data | ./finder count 33000 10000
Number of matching entries = 150000000. Time taken = 0.168173s

cat data | ./finder count 2000 10000
Number of matching entries = 74950000. Time taken = 0.68349s

cat data | ./finder count 2000 10000
Number of matching entries = 74950000. Time taken = 0.672462s
```

Run Benchmarks **mitigations=on** for `Python`

```
$ cat data | ./find.py count 200000 10000
Number of matching entries = 15000. Time taken = 0.0005381107330322266
$ cat data | ./find.py count 200000 10000
Number of matching entries = 15000. Time taken = 0.0005354881286621094


$ cat data | ./find.py count 2000 10000
Number of matching entries = 7495. Time taken = 0.0004603862762451172
$ cat data | ./find.py count 2000 10000
Number of matching entries = 7495. Time taken = 0.000484466552734375
```
