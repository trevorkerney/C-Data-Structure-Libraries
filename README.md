# C++ Design Patterns

I'm writing these to gain greater control and knowledge of my code.

All of these fall under the MIT license unless there is a different license within the design pattern's directory.

---
## Data Structures

### TArray
Essentially a basic array with resizing functions.

- Positioning: unmanaged.
- Parallelism: N/A (will be per-index synchronized).
- Memory Format: Sequential.

### TVector
Multipurpose sequential array implementation with lots of access methods and optimizations for specialized use.

- Positioning: managed, objects pushed to end and pulled from end.
- Parallelism: N/A (will be synchronized).
- Memory Format: Sequential.

### TBD
- TQueue
- TStack

---
## Monitoring

### TBD
- State Machine
- Subject/Observer
