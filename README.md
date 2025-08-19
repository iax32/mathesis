
   _____          __  .__                  .__        
  /     \ _____ _/  |_|  |__   ____   _____|__| ______ <br>
 /  \ /  \\__  \\   __\  |  \_/ __ \ /  ___/  |/  ___/ <br>
/    Y    \/ __ \|  | |   Y  \  ___/ \___ \|  |\___ \  <br>
\____|__  (____  /__| |___|  /\___  >____  >__/____  > <br>
        \/     \/          \/     \/     \/        \/ <br>
Lightweight C++ math library for game hacking, provides vector and matrix types (2D, 3D, 4D) with common operations like dot, cross, normalization, distance, lerp, and more. Designed to be header-only, minimal, and memory-friendly for direct use with game engines or memory manipulation.
Ahh I see what you mean now — you don’t want the README to look like a shopping list with bullets everywhere 😅
Here’s the same content rewritten in a **smoother, prose-style format** while still being clear:

---

# Features

This library is header-only and depends only on `<cmath>`, `<ostream>`, and `<algorithm>`. It is fully C++17-ready (using `std::clamp`), but can be adapted for earlier standards by replacing it with `min/max`. The API is consistent across `vector2`, `vector3`, `vector4`, and a simple `matrix` type.

# Vectors

All vector types come with constructors for zero-initialization or component-wise initialization. Arithmetic is supported in a natural way: you can add, subtract, multiply, or divide vectors element-wise, and scale them with floats on either side (`vec * s` or `s * vec`). Compound assignments like `+=`, `-=`, `*=`, and `/=` are also provided, along with unary negation.

Equality and inequality are defined as exact float comparisons (you can swap in an epsilon check if you need fuzzy math). Each vector supports `dot()` products, and `cross()` is available as well: in 3D it returns another vector, while in 2D it gives a scalar representing the signed area. You also get `length()`, `length_squared()`, `normalized()` (copy), and `normalize()` (in-place).

For convenience, utility methods like `distance()`, `lerp()`, and `clamp()` are included, along with `operator<<` for easy printing.

# Matrix

The matrix type is a very simple struct:

```cpp
struct matrix {
    float mvp_matrix[16];
};
```

It’s just a contiguous 16-float array, which makes it trivial to upload to a GPU or pass into graphics APIs. The struct can easily be extended with identity, perspective, transform builders, or with `matrix * vector` / `matrix * matrix` operations.

# Example

```cpp
vector3 a{1,2,3}, b{4,5,6};
auto c = a + b;                 // (5,7,9)
auto h = a * b;                 // Hadamard: (4,10,18)
float d = a.dot(b);             // 32
auto x = a.cross(b);            // (-3,6,-3)
auto n = a.normalized();        // unit-length copy
```

Tip: For float equality, consider replacing `==` with an epsilon-based comparison to avoid precision pitfalls.

---

