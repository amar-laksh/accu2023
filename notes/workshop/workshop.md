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
- ASIDE: use hidden friends instead of freestanding functions for operator implementations.

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
- Two problems: caching and constant propagation.

## Spans
- `std::span` is a generalization of the `std::string_view` for basically any pointer.
- Also, it can be thought of a view. 
- It provides a range API.
- Be careful to not use spans when they refer to invalid elements/memory.
- Again, it follows the rules of pointers.
- It's good in cases if you need to jump to the nth element. (It has contiguous memory and the iterator is contiguous category)
- We need to make sure that we are sending compile time type parameters when calling positional methods on span.
- They don't propagate constants.

## Threads
-  NOTE: `.join()` is not `noexcept` in `std::thread`.
- `std::jthread` have two main advantages: joins automatically, handles exceptions by pausing threads and polling can be done using stop tokens.
- QUESTION: stop tokens are similar to `nod::signals`?
- `jthreads` request stop and join automatically.

## Concurrency
- `std::latch` has `arrive_and_wait()` can sync all threads while they run.
- `atomic_ref` can be used to make values temporarily atomic.
-  Atomic types now have a notification API. So you don't have to use a conditional variable along with atomic ones to notify and wait.
- `std::osyncstream` synchronized output streams collect all the output and then flush it at the end on request. This could be useful for debugging applications. All of this is not just synchronized but also collected before flushing. It can also be useful for collecting all output in a scope.

## Module
- It provides a clear, distinct set of APIs for users also helps incidentally with compile times.
- ASIDE: learn about explicit instantiation declaration: `extern template`

## Calendars and Time Zones
- The output operator handles the units and count for `chrono::duration`s.
- Also, can use it with `std::format`
- It now supports calendar alias names. (Months, Years etc.)
- Remember to use `steady_clock` instead of the `system_clock`
- `clock_cast` is available now.

## Co-routines
- `co_await` actually makes a function a co-routine, not the return type.
- The return type is not a value but a `CoroTask` which is the co-routine interface through which we can interact with the co-routine. It also contains the configuration to deal with the co-routine, to select which kind of co-routine we have.

## Misc
- `constexpr` requires compile-time evaluation.
- `std::is_constant_evaulated()` yields true for the above.
- `Non-type Template parameter types` are now supported.
