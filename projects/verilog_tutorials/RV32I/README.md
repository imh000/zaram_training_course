# RISC-V Pipelined CPU
![스크린샷 2024-08-22 130828](https://github.com/user-attachments/assets/7043bea5-88f8-4d59-bef0-409a33e6928d)
## IF stage
- Fetch instruction from memory
- PC update
## ID stage
- Decode the instruction
- Read registers
## EX stage
- Execute the operation
- calculate PC
## MEM stage
- Access an operand in data memory (if necessary)
## WB stage
- Write the result into a RD registers (if necessary)
## Verilator result
![스크린샷 2024-08-22 133420](https://github.com/user-attachments/assets/73774830-4ab4-499a-8a00-b2f3f634f096)
