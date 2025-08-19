# mathesis
Lightweight C++ math library for game hacking, provides vector and matrix types (2D, 3D, 4D) with common operations like dot, cross, normalization, distance, lerp, and more. Designed to be header-only, minimal, and memory-friendly for direct use with game engines or memory manipulation.

Here’s a short, copy-pasteable **Features & Capabilities** section for your README:

# Features

* **Header-only**, minimal dependencies (`<cmath>`, `<ostream>`, `<algorithm>`).
* **C++17-ready** (`std::clamp`); works with older standards if you replace it with `min/max`.
* Consistent API across **vector2**, **vector3**, **vector4** + a simple **matrix** container.

# vector2 / vector3 / vector4

* **Constructors**

  * Default zero-initialized components.
  * Component-wise constructor: `vectorN(float x, float y[, z[, w]])`.

* **Arithmetic (component-wise)**

  * Binary: `+  -  *  /` (vector ⊗ vector; Hadamard for `*`/`/`)
  * Scalar: `vec * s`, `s * vec`, `vec / s`
  * Compound: `+=  -=  *=  /=` (both vector and scalar forms)
  * Unary: `-vec`

* **Comparisons**

  * Exact float equality/inequality: `==`, `!=` (easy to swap to epsilon if desired)

* **Vector math**

  * `dot()` for all vectors
  * `cross()`:

    * `vector3::cross()` → 3D vector result
    * `vector2::cross()` → scalar (signed area / z-component)
  * `length()`, `length_squared()`
  * `normalized()` (returns copy), `normalize()` (in-place; safe for zero length)

* **Utilities**

  * `distance(a, b)`
  * `lerp(a, b, t)`
  * `clamp(v, min, max)` (component-wise)
  * Stream output: `operator<<` → `(x, y[, z[, w]])`

* **Design notes**

  * Non-compound ops are implemented via compound ones for consistency and less duplication.
  * Symmetric scalar ops supported (`s * vec` and `vec * s`).

# matrix

* **Memory layout**

  * `struct matrix { float mvp_matrix[16]; };`
  * Plain 16-float storage suitable for GPU uploads / API calls (contiguous memory).

* **Extendable**

  * Easy to add identity/perspective/transform builders and `matrix * vector` / `matrix * matrix` later.

# Example (quick peek)

```cpp
vector3 a{1,2,3}, b{4,5,6};
auto c = a + b;                 // (5,7,9)
auto h = a * b;                 // Hadamard: (4,10,18)
float d = a.dot(b);             // 32
auto x = a.cross(b);            // (-3,6,-3)
auto n = a.normalized();        // unit-length copy
```

> Tip: For fuzzy float comparisons, replace `==` with an epsilon check to suit your project.

