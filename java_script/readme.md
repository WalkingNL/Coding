
## the order to execute a javascript program
### scripts are loaded
#### who and how does the action of loading scripts

  this action is done by explorers from HTMLs or some other external files

    <script src="js/styles.js"></script>

### scripts are parsed
### execution context are created
### scripts are executed
#### synchronous code runs first, line by line
#### asynchronous code (callback, promises) is handled by the Event loop and processed later
#### microtasks (e.g., Promises) are executed before tasks (e.g., setTimeout)
