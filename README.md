
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


## Kernel Vulnerability Status

With `mitigations=auto` 

```yaml
Architecture:                    x86_64
CPU op-mode(s):                  32-bit, 64-bit
Byte Order:                      Little Endian
Address sizes:                   39 bits physical, 48 bits virtual
CPU(s):                          20
On-line CPU(s) list:             0-19
Thread(s) per core:              2
Core(s) per socket:              10
Socket(s):                       1
NUMA node(s):                    1
Vendor ID:                       GenuineIntel
CPU family:                      6
Model:                           165
Model name:                      Intel(R) Core(TM) i9-10900K CPU @ 3.70GHz
Stepping:                        5
CPU MHz:                         2941.452
CPU max MHz:                     5300.0000
CPU min MHz:                     800.0000
BogoMIPS:                        7399.70
Virtualization:                  VT-x
L1d cache:                       320 KiB
L1i cache:                       320 KiB
L2 cache:                        2.5 MiB
L3 cache:                        20 MiB
NUMA node0 CPU(s):               0-19
Vulnerability Itlb multihit:     KVM: Mitigation: VMX disabled
Vulnerability L1tf:              Not affected
Vulnerability Mds:               Not affected
Vulnerability Meltdown:          Not affected
Vulnerability Spec store bypass: Mitigation; Speculative Store Bypass disabled via prctl and seccomp
Vulnerability Spectre v1:        Mitigation; usercopy/swapgs barriers and __user pointer sanitization
Vulnerability Spectre v2:        Mitigation; Enhanced IBRS, IBPB conditional, RSB filling
Vulnerability Srbds:             Not affected
Vulnerability Tsx async abort:   Not affected
Flags:                           fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_t
                                 sc cpuid aperfmperf pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch cpuid_fau
                                 lt invpcid_single ssbd ibrs ibpb stibp ibrs_enhanced tpr_shadow vnmi flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 avx2 smep bmi2 erms invpcid mpx rdseed adx smap clflushopt intel_pt xsaveopt xsavec xgetbv1 xsaves
                                  dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp pku ospke md_clear flush_l1d arch_capabilities
```


With `mitigations=off` 

```yaml
Architecture:                    x86_64
CPU op-mode(s):                  32-bit, 64-bit
Byte Order:                      Little Endian
Address sizes:                   39 bits physical, 48 bits virtual
CPU(s):                          20
On-line CPU(s) list:             0-19
Thread(s) per core:              2
Core(s) per socket:              10
Socket(s):                       1
NUMA node(s):                    1
Vendor ID:                       GenuineIntel
CPU family:                      6
Model:                           165
Model name:                      Intel(R) Core(TM) i9-10900K CPU @ 3.70GHz
Stepping:                        5
CPU MHz:                         3700.000
CPU max MHz:                     5300.0000
CPU min MHz:                     800.0000
BogoMIPS:                        7399.70
Virtualization:                  VT-x
L1d cache:                       320 KiB
L1i cache:                       320 KiB
L2 cache:                        2.5 MiB
L3 cache:                        20 MiB
NUMA node0 CPU(s):               0-19
Vulnerability Itlb multihit:     KVM: Mitigation: VMX disabled
Vulnerability L1tf:              Not affected
Vulnerability Mds:               Not affected
Vulnerability Meltdown:          Not affected
Vulnerability Spec store bypass: Vulnerable
Vulnerability Spectre v1:        Vulnerable: __user pointer sanitization and usercopy barriers only; no swapgs barriers
Vulnerability Spectre v2:        Vulnerable, IBPB: disabled, STIBP: disabled
Vulnerability Srbds:             Not affected
Vulnerability Tsx async abort:   Not affected
Flags:                           fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_t
                                 sc cpuid aperfmperf pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch cpuid_fau
                                 lt invpcid_single ssbd ibrs ibpb stibp ibrs_enhanced tpr_shadow vnmi flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 avx2 smep bmi2 erms invpcid mpx rdseed adx smap clflushopt intel_pt xsaveopt xsavec xgetbv1 xsaves
                                  dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp pku ospke md_clear flush_l1d arch_capabilities
```