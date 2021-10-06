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

### TQueue (incomplete)
Queue implementation, objects pushed to end and pulled from start.

- Positioning: managed.
- Parallelism: N/A (will be synchronized).
- Memory Format: Nonsequential, linear.

### TStack (AKA TLinkedVector) (incomplete)
Stack implementation, objects pushed to top and pulled from top.

- Positioning: managed.
- Parallelism: N/A (will be synchronized).
- Memory Format: Nonsequential, linear.

### TVector
Multipurpose sequential array implementation with lots of access methods and optimizations for specialized use.

- Positioning: managed, objects pushed to end and pulled from end.
- Parallelism: N/A (will be synchronized).
- Memory Format: Sequential.

---
## Monitoring

### State Machine (TBD)
### Subject/Observer (TBD)
