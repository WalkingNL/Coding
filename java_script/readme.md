
## the order to execute a javascript program
### scripts are loaded
### scripts are parsed
### execution context are created
### scripts are executed
#### synchronous code runs first, line by line
#### asynchronous code (callback, promises) is handled by the Event loop and processed later
#### microtasks (e.g., Promises) are executed before tasks (e.g., setTimeout)
