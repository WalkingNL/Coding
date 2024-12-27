
## the order to execute a javascript program
### scripts are loaded
#### who and how does the action of loading scripts

- this action is done by explorers from HTMLs or some other external files

  ```HTML
  <script src="js/styles.js"></script>
  ```
- the loading time of java scripts

  scripts might be marked with different HTML attributes like `async` or `defer`, it affects **when** and **how** the script is executed.
  - `inline` scripts.

    execute as they are encountered
   
    ```HTML
    <!-- inline scripts -->
    <script src="js/styles.js"></script>
    ```
  
  - `async` scripts

    the script is executed asynchronously with the rest of the page. It does not block the parsing of the HTML document and will execute as soon as it is downloaded.

    ```HTML
    <!-- Asynchronous script loading -->
    <script async src="https://www.googletagmanager.com/gtag/js?id=UA-XXXXX-Y"></script>
    <script>
      window.dataLayer = window.dataLayer || [];
      function gtag(){dataLayer.push(arguments);}
      gtag('js', new Date());
      gtag('config', 'UA-XXXXX-Y');
    </script>
    ```

  - `defer` scripts
 
    the script is executed after the HTML document has been fully parsed. It ensures that the script runs in the order they appear in the document.

    ```HTML
    <!-- Deferred script loading -->
    <script defer src="scripts/main.js"></script>
    ```

### scripts are parsed

  to change the js code into a structure called the Abstract Syntax Tree (AST), this is done to analyze and understand the code structure.

### execution context are created
### scripts are executed
#### synchronous code runs first, line by line
#### asynchronous code (callback, promises) is handled by the Event loop and processed later
#### microtasks (e.g., Promises) are executed before tasks (e.g., setTimeout)
