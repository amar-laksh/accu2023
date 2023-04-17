## Comparisons
- Implicit inequality operator is introduced
- implicit type conversion for comparisons is fixed. (now works for both operands)
- Implicit type conversion should be thought about when you might already have the fixes for the type conversion fixes in place.
- Compiler checks the comparisons and automatically corrects the order of the comparison. (no need for a hidden friend)
- Comparison operators can also be defaulted (if it's constant)
- `<=>` spaceship operator resolves all inequality comparisons.
- If you default spaceship operator, then you don't need to default or implement equality operator.
- `auto` in the spaceship operator needs to be thought in terms of the ordering type for your class members. (It might need to be `std::partial_ordering` or `std::strong_ordering`)
- `std::strong_ordering` can be converted to `std::partial_ordering` but not the other way round.
- `std::compare_strong_order_fallback()` works without spaceship operator implementations 

## Concepts
- We use concepts to put constraints on the code (We can also use it directly as a type constraint). The concept is the compile-time boolean value returned from the `requires` call that checks the constraints. Using these constraints we just toggle the visibility of the code for the compiler at compile-time. 
- Abbreviated function template syntax (`ABFTS`) is just a function template shorthand.
- Template parameters come first and then `ABFTS` parameters.
- Template parameters should only be used if you wanna explicitly specify type names.
- The requirements parameters should be thought clearly. The requirements should apply to both parameters. 
- Concepts should be used as broad categories by combining multiple requirements, not fine-grained.
- QUESTION what about using lambdas inside concept requirements? Using mutual recursion inside concepts? What about structured bindings?
- Compile time ifs and requires can be very useful for compile-time evaluation.
- Use ranges::sort since it has more strict requirements (check sortable and its other constraints)
- Be careful about the different applications of `requires` keyword. (Defining requirements vs Defining constraints)
- `concept` and `constexpr bool` are different because `concept` can hold specialization relationships.
- We should remember that all these concept checks have compile-time costs.
- Use the cowboy example to show the essence of correct concepts. (Concept's don't automatically subsume)
- ASIDE: use concept to implement `std::variant`
- Take care of the order of parameters when using Concepts.


## Iterators
- Explain the changes and old ones.

## Views
- We need to remember that views don't provide expensive functions for efficient calls.
- We can take advantage of the caching mechanisms for views.
- Use `bel::views`.
