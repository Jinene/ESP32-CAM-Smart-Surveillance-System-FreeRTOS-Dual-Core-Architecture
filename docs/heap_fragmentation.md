# Heap Fragmentation in Embedded Systems

Heap fragmentation occurs when:

- Many malloc/free operations happen
- Different sizes are allocated dynamically
- Memory becomes divided into unusable blocks

Solution in this project:

- Static buffers when possible
- PSRAM for large camera buffers
- Avoid frequent malloc/free inside loops
- Monitor largest free block
