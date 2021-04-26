# 	FPGA Finite difference

This repo contains a rtl implementation of the  **forward difference** expression, util to apromimate the numerical differentiation



## Requirements

* `verilator`
* 

## Usage

To run the test 

```bash
$ make 
```

This give you the information if the implementation pass the test or not.  If you want to visualize the wave, you can use gtkwave and display the timing digram using

```bash
$ gtkwave fwht_trace.vcd
```

|        Input         | Current State | Next State |   Output   |                                      |
| :------------------: | :-----------: | :--------: | :--------: | ------------------------------------ |
|       `Start`        |    *IDLE*     |    *S1*    | `00000000` |                                      |
|         `X`          |     *S1*      |    *S2*    | `11000000` | Save Input 1 **(Dy)**                |
|         `X`          |     *S2*      |    *S3*    | `11010000` | Save Input 1 **(Dy)**                |
|         `X`          |     *S3*      |    *S3*    | `11011000` | Save Input 2 **(Dy)** and Write FIFO |
|      ` ~o_full`      |     *S4*      |    *S3*    | `11111100` | Full FIFO                            |
|      ` o_full`       |     *S4*      |    *S4*    | `11111100` | Full FIFO                            |
|         `X`          |     *S5*      |    *S5*    | `11111101` | Read FIFO                            |
|         `X`          |     *S6*      |    *S6*    | `11111101` | Save Input 2 **(Dx)**                |
|     `(&Counter)`     |     *S7*      |    *S7*    | `11111111` | Wait and save results                |
|    `~(&Counter)`     |     *S7*      |    *S6*    | `11111111` | Wait and save results                |
|         `X`          |     *S8*      |    *S8*    | `11111111` | Save last Input 2 **(Dy)**           |
|         `X`          |     *S9*      |    *S9*    | `11110111` | Save last Result **(Dy)**            |
| `(&column_counter)`  |     *S10*     |    *S9*    | `11110011` | Wait And save results                |
| `~(&column_counter)` |     *S10*     |   *S10*    | `11110011` | Wait And save results                |
|         `X`          |     *S11*     |   *S111*   | `10000010` | Save last Input 2 **(Dx)**           |
|         `X`          |     *S12*     |   *IDLE*   | `10000010` | Save last Result **(Dx)**            |



## License

MIT License

Copyright (c) 2021 Andres Manjarres

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.