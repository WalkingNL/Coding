# vim

## relative configuration file

- .vimrc
- .viminfo

### introduction

#### .vimrc

- what does the file do
  > to configure vim settings
- where is the file placed
  > your home directory. ~/.vimrc
- how should i do if the file does not exist
  > to create this file using command `vim ~/.vimrc`, and input the content below

    `.vimrc` file
  
    ```txt
    " configuration file for vim 

    " disable modelines for security (cve-2007-2438)
    set modelines=0

    " normally we use vim-extensions. if you want true vi-compatibility
    " remove change the following statements
    set nocompatible        " use vim defaults instead of 100% vi compatibility
    set backspace=2         " more powerful backspacing

    " don't write backup file if vim is being called by "crontab -e" 
    au bufwrite /private/tmp/crontab.* set nowritebackup nobackup

    " don't write backup file if vim is being called by "chpass"
    au bufwrite /private/etc/pw.* set nowritebackup nobackup

    " skip loading default vim settings
    let skip_defaults_vim=1

    ```
  
- how to test whether the `.vimrc` file is configured correctly
    > to append one statement shell command `echo "loaded .vimrc"` to the end of the content from this file, and then `save & exit`. when vim run again, the statement "loaded .vimrc" would be printed on the screen, which means this file previously added is successful, but if not, we need to check whether other problems exist.  

#### .viminfo

this file is used to save state information between vim sessions.

- case 1:
  > when exiting vim, the `marks` and `jumps` that you’ve created are lost. how shoudl we do?

  answer: to save the `marks` you’ve created by making use of the `viminfo` file, which saves state information between vim sessions.

**question**:

1. this feature to save marks is not enabled when exiting vim, how to solve this?
    > to append this statement `set viminfo='100,f1` to the .vimrc file. the '100 tells vim to save marks and other information for up to 100 files. the f1 directive tells vim to also save global marks (a-z) when it exits. if you don’t want vim to do this, set it to f0 instead.

### basic operation

#### moving cursor operaiton
   1. `h`,`j`,`k`,`l`
   2. `w` and `b` moves the cursor forward or backward by one word, the cursor lies at the frist character of each word. `w` and `b` also like this. `e` and `ge`, `e` and `ge` are the same function as the command `w` and `b`, but the cursor lies at the last word of each word.
      ```txt
   	           ge      b	        w         		              e
	           <-     <-	       --->			                 --->
	    this is-a line, with special/separated/words (and some more). 
	       <----- <-----	       -------------------->	     ----->
	         gE      B			        W	          		    E

      ```
   3. `0` and `^` move the cursor to the beginning of lines. `g_` and `$` move the cursor to the end of lines.
       - `0`: This command moves the cursor to the beginning of the line, including any leading whitespace (like spaces and tabs).
       - `^`: This command moves the cursor to the first non-blank character of the line.
          ```txt
       		          ^
	             <------------
	        .....This is a line with example text 
	        <-----------------   --------------->
		             0		           $
          ```
       
       - `g_`: moves the cursor to the last non-blank charcter of the line.
       - `$`: moves the cursor to the end of the line, including any leading whitespace (like spaces and tabs).
#### return to the last position
`
     - <u>``</u> (two backticks) or `‘’` (two apostrophes): These commands return the cursor to the exact spot or the start of the line of the last modification, respectively.

     - `g;`: This command moves the cursor to the last change.
     - `Ctrl-o(O)`: This command retraces your movements in the file backwards.
     - `Ctrl-i(I)`: This command retraces your movements in the file forwards.

#### deleting, inserting, replacing operation

- deleting

  - `x` will delete a character under the cursor
  - `d` can be used to delete larger selections of text
    - `d3l` will delete 3 characters to the right
      - Note that we’re combining an operation, a movement, and a count here
    - `d4h` will delete 4 characters to the left
    - `dd` will delete a single line
    - `d$` or `D` will delete content from the cursor to the end of the line
    - `d0` will delete from the cursor to the start of the line
  - `:7,10d` will delete lines 7 to 10 in command mode
    - `7,10` is a “range”
  - `a`: enter the insert mode at the next position.
  - `A`: enter the insert mode at the end of a line.
  - `s`: delete the current character under the cursor and enter the insert mode.
  - `S`: delete the current line and enter the insert mode.
  - `i`: enter the insert mode at the cursor.
  - `I`: enter insert mode at the beginning of the current line.
  - `o`: enter the insert mode at the next line.
  - `O`: enter the insert mode at the previous line.
  - `c`: is used to delete the current selection and enter the insert mode that `c` can be used with other motion.
    - `cw` or `cb`: delete the current or next or previous word and then enter the insert mode.
      - `cc`, delete a whole line and then enter the insert mode.
    - `c$` or C, delete the content from the current cursor to the end of the line, and then enter the insert mode.
    - `ci(` or `ci)`, delete the content within a `()` which is next to the cursor and then enter the insert mode. `ci[` or `ci]`, `ci{` or `ci} do the same way.
- inserting
- replacing
  - `r`, only replace one character and exit the replacing mode
  - `R`, Enter Replace mode: Each character you type replaces an existing character, starting with the character under the cursor.  Repeat the entered text [count]-1 times.
  - `gr`, Replace the virtual characters under the cursor with {char}.  This replaces in screen space, not file space.
  - `gR`, Enter Virtual Replace mode: Each character you type replaces existing characters in screen space.  So a <Tab> may replace several characters at once. Repeat the entered text [count]-1 times.

- swiching upper(lower)case
  - `~` 'notildeop' option: Switch case of the character under the cursor and move the cursor to the right. If a [count] is given, do that many characters. {Vi: no count}

    ```vim
    ~, switch case at a character each time 

    [number]~, change the case right to number-1 position each time 
    ```

  - `~{motion}` 'tildeop' option: switch case of {motion} text.

  - `g~{motion}` Switch case of {motion} text. {not in Vi}
    - `g~iw`, this will change the case of the entire word of the cursor

  - `g~g~` or `g~~`, Switch case of current line. {not in Vi}.

  - `{Visual}~` Switch case of highlighted text. {not in Vi}

  - `{Visual}U` Make highlighted text uppercase {not in Vi}

  - `gU{motion}` Make {motion} text uppercase. {not in Vi}
  
      Example:

      ```vim
        :map! <C-F> <Esc>gUiw`]a
      ```

      This works in Insert mode: press CTRL-F to make the word before the cursor uppercase.  Handy to type words in lowercase and then make them uppercase.

  - `gUgU` and `gUU`, Make current line uppercase. {not in Vi}.

  - `{Visual}u` Make highlighted text lowercase {not in Vi}

  - `gu{motion}` Make {motion} text lowercase. {not in Vi}

  - `gugu` and `guu`, Make current line lowercase. {not in Vi}.

  - `g?{motion}` Rot13 encode {motion} text. {not in Vi}

  - `{Visual}g?` Rot13 encode the highlighted text.  {not in Vi}

  - `g?g?` and `g??`, Rot13 encode current line. {not in Vi}.

  To turn one line into title caps, make every first letter of a word
uppercase:

  ```vim
  :s/\v<(.)(\w*)/\u\1\L\2/g
  ```

  > - `\v`: Enables 'very magic' mode, which makes the regular expression syntax more concise by reducing the need for backslashes.
  > - `<`: This matches the beginning of a word. In Vim, < is a zero-width assertion that matches the position where a word starts.
  > - `.`: This matches any single character except a newline.
  > - `(\w*)`: This is a capturing group that matches zero or more word characters. \w matches any word character (equivalent to [a-zA-Z0-9_]), and * means "zero or more" of the preceding character or group.
  > - `\u\1`: Converts the first captured group (the single character) to uppercase. `u` refers to uppercase. using lowercase `u` represents converting the matched lowercase characters to uppercase, if the matched characters are uppercase, it does nothing.
  > - `\L\2`: Converts the second captured group (the rest of the word) to lowercase. `L` refers to lowercase. using uppercase `L` represents converting the matched uppercase characters to lowercase, if the matched characters are lowercase, it does nothing.
  > - `g`: Global flag, meaning it will apply the substitution to all matches in each line.


#### Undo, Redo and Repeat
Vim knows we’re going to make mistakes, and it’s happy to bail us out!
    - Vim knows we do awesome work, and it’s happy to help us repeat it!
    - To undo the last operation (we won’t say “mistake”) type u in normal mode.
    - To redo (undo the undo) the last operation type `CTRL-r` in normal mode.
    - To repeat an operation you’ve just done use `.` in normal mode.
    - Example: If you enter insert mode and type “Vim is nifty” and then return to normal mode (Esc) and type `.` then Vim will repeat “Vim is nifty.”
    - These are usually modifiable. Let’s talk about that next.
#### find a single character within a line.
    ```txt
    To err is human.  To really foul up you need a computer. 
    ---------->--------------->
	      fh	        fy
    ```

    `3fl` command, `3` means that moves to the third matched character from the current cursor in a line.
    ```txt
    To err is human.  To really foul up you need a computer. 
		      --------------------->
			             3fl
    ```
    ```txt
    To err is human.  To really foul up you need a computer. 
		      <---------------------
			            Fh    
    ```
    `t` or `T` likes `f` or `F`. except it stops one character before the searched character. These four commands can be repeated with `;`. `,` repeats in the other direction.
    ```txt
    To err is human.  To really foul up you need a computer. 
		       <------------  ------------->
			        Th              tn
    ```
#### scrolling around

- `ctrl b(B)` command
- `ctrl u(U)` command
- `ctrl d(D)` command
- `ctrl f(F)` command
- `ctrl e(E)` command, scrolling up line by line.
- `ctrl y(Y)` command, scrolling down line by line.
- `zz` command
  ```txt
	  +------------------+		     +------------------+
	  | some text	       |		     | some text	    |
	  | some text	       |		     | some text	    |
	  | some text	       |		     | some text	    |
	  | some text	       |   zz  -->	 | line with cursor |
	  | some text	       |		     | some text	    |
	  | some text	       |		     | some text	    |
	  | line with cursor |		     | some text	    |
	  +------------------+		     +------------------+
  ```

#### merging lines

- `J` and `gJ`, merging multiple lines into one line. The difference is that using `J` command would append the back lines of the cursor to the end of the current line and add (one or two) space(s) between two lines merged, but using `gJ` command would not addd any space between the two merged lines.
- `:[range]j`, joining a range of lines.

  ```vim
  :j(oin), joining two lines (including the current line)
  :3j, joining three lines (including the current line) into one line with two modifying spaces
  :15,17j, specifying a range of lines and joining with one (or two) modifying spaces
  :15,17j!, ! means without any modifying spaces added.
  ```

#### Adding and subtracting

- `Ctrl-A(a)`, adding 1 on a number at cursor.
- `Ctrl-X(x))`, subtracting 1 on a number at cursor.

#### SHIFTING LINES LEFT OR RIGHT

- `{Visual} <(>) {motion}`
- `{Visual} <<(>>)`
- commanding line in Vim
  - `:[range]<` Shift [range] lines one 'shiftwidth' left.  Repeat `<` for shifting multiple 'shiftwidth's.

  - `:[range]< {count}` Shift {count} lines one 'shiftwidth' left, starting with [range] (default current line |cmdline-ranges|). Repeat `<` for shifting multiple 'shiftwidth's.

  - `:[range]le[ft] [indent]` left align lines in [range]. Sets the indent in the lines to [indent] (default 0).

  - `:[range]> [flags]` Shift {count} [range] lines one 'shiftwidth' right. Repeat `>` for shifting multiple 'shiftwidth's. See |ex-flags| for [flags].

  - `:[range]> {count} [flags]` Shift {count} lines one 'shiftwidth' right, starting with [range] (default current line |cmdline-ranges|). Repeat `>` for shifting multiple 'shiftwidth's. See |ex-flags| for [flags].

### advanced operation

- the fold function in vim

  - basic commands:

    - `zf` or `zF`, like `zf10j` or `zf10k`,
    - `zo`, open the fold. Open one fold under the cursor.  When a count is given, that many folds deep will be opened. In Visual mode one level of folds is opened for all lines in the selected area.
    - `zO`, Open all folds under the cursor recursively. Folds that don't contain the cursor line are unchanged. In Visual mode it opens all folds that are in the selected area, also those that are only partly selected.
    - `zc`, Close one fold under the cursor.  When a count is given, that many folds deep are closed.  In Visual mode one level of folds is closed for all lines in the selected area. 'foldenable' will be set.
    - `zC`, Close all folds under the cursor recursively.  Folds that don't contain the cursor line are unchanged. In Visual mode it closes all folds that are in the selected area, also those that are only partly selected. 'foldenable' will be set.
    - `za`, When on a closed fold: open it.  When folds are nested, you may have to use "za" several times.  When a count is given, that many closed folds are opened. When on an open fold: close it and set 'foldenable'.  This will only close one level, since using "za" again will open the fold.  When a count is given that many folds will be closed (that's not the same as repeating "za" that many times).
    - `zA`, When on a closed fold: open it recursively. When on an open fold: close it recursively and set 'foldenable'.
    - `zd`, delete the fold under the cursor. Delete one fold at the cursor. When the cursor is on a folded line, that fold is deleted.  Nested folds are moved one level up.  In Visual mode all folds (partially) in the selected area are deleted.  Careful: This easily deletes more folds than you expect and there is no undo. This only works when 'foldmethod' is "manual" or "marker". Also see |fold-delete-marker|.
    - `zD`, Delete folds recursively at the cursor.  In Visual mode all folds (partially) in the selected area and all nested folds in them are deleted. This only works when 'foldmethod' is "manual" or "marker". Also see |fold-delete-marker|.
    - `zE`, eliminate all the fold in the window.
    - `]z`, Move to the end of the current open fold.  If already at the end, move to the end of the fold that contains it.  If there is no containing fold, the command fails. When a count is used, repeats the command [count] times.
    - `[z`, Move to the start of the current open fold.  If already at the start, move to the start of the fold that contains it.  If there is no containing fold, the command fails. When a count is used, repeats the command [count] times.
    - `zj(k)`, moving down(up) to the start of the next fold.
    - `fold`, like `:10,20fold`
- recording in vim

  ```txt
  a) the scenery of Chang'an is in my memory.
  b) the scenery of Chang'an is in my memory.
  c) the scenery of Chang'an is in my memory.
  d) the scenery of Chang'an is in my memory.
  e) the scenery of Chang'an is in my memory.
  f) the scenery of Chang'an is in my memory.
  g) the scenery of Chang'an is in my memory.
  h) the scenery of Chang'an is in my memory.
  i) the scenery of Chang'an is in my memory.
  j) the scenery of Chang'an is in my memory.
  ```
  
  to auto-increment the list number in recording in Vim.
  1. check the `nrformats` option whether supports the alpha self-incrementing. If doesn't, we need to append `alpha` value to this option in ~/.vimrc file, and then judge if it works with command: `set nrformats?`.
  2. `qa`, enter the recording state.
  3. `Y`, copy the first line.
  4. `p`, paste.
  5. `Ctrl-A`, self-incrementing.
  6. `q`, quiting the recording state.
  7. `9@a`, replaying a, which would repeat the yank process and increment 9 times.

- diffs between files
  - basic commands
    - `vimdiff [-o] file1 file2 ...` or `vim -d[o] file1 file2 ...` or `:[vert] diffsplit file_cmp` or `diffthis`

        how to use `diffthis` command in Vim
  
        1. `:vsplit` to split vertically the current window and open the compared file.
        2. using `:diffthis` command in both window

    - `]c` and `[c`, jump forwards to the next start of a change.
    - `[c`, jump backwards to the previous start of a change.
  - view diffs
    - `wrap`
    - `scrollbind`
    - `folds`
    - "filler"
  - merging files commands
  
    There are two commands to copy text from one buffer to another.  The result is
that the buffers will be equal within the specified range.
    - `[range] diffget(diffg, do) [bufspec]`, Used to apply changes from another buffer to the current buffer. This is useful when you want to accept changes from another version of a file into your current working file.
    - `[range] diffput(diffpu, dp) [bufspec]`, Used to apply changes from the current buffer to another buffer. This is useful when you want to push your changes to another version of the file.

      ```vim
      diffput 2
      ```

      no range is specified, but the bufspec is 2, which is that using buf 2 to override the current.

    - other

      ```vim
      diff file1 file2 > output
      patch -o outfile origfile < patchfile
      ```

  - using autocmd

    - `:au[tocmd] [group] {event} {pat} [nested] {cmd}`, Add {cmd} to the list of commands that Vim will execute automatically on {event} for a file matching {pat} |autocmd-patterns|. Vim always adds the {cmd} after existing autocommands, so that the autocommands execute in the order in which they were given.

### visual mod

Visual [Character] mode: Used for selecting individual characters.          [press v]
Visual Line mode: Used for selecting a whole line at once                   [press V]
Visual Block mode: Used to select text in a block-style rectangular shape   [press ctrl+v]

When you switch to Visual mode, Vim will give you some details. It will show which mode you are in and the amount of text that you have selected.

Once you are in Visual mode, selection starts from your cursor's point, and you can move it using the navigational keys h/j/k/l.

When you are satisfied the selection, you can perform operations like delete, yank and replace.

Visual [Character] mode
As mentioned above, this is used for moving the cursor over individual characters. But it is not limited to selecting single characters. Just like Normal mode, you can jump over words with w/e/b keys and go up/down with k/j keys, respectively.

I will demonstrate selecting an individual character, selecting a few words, selecting an entire line, and then delete the selection using Visual [Character] mode.

---

### Command-Line Mode

- Substitution: Use `:%s/old/new/g` to replace "old" with "new" in the entire file. Use `:s/old/new/g` for the current line.
- Global Command: Execute a command on all lines matching a pattern.
  - Example: `:g/pattern/command`.
  - Example: `:g/error/d` deletes all lines containing the word "error".

### Using Buffers, Windows, and Tabs

- **Buffers**: Manage multiple open files.
  - **Example**: :`e filename` to open a file, `:ls` to list open buffers, `:bN` to switch to buffer N.
- **Windows** **`:Split`** the screen to view multiple files or parts of a file.
  - Example: **`:split`** or **`:vsplit`** to split horizontally or vertically, **`Ctrl-w w`** to switch between windows, **`ctrl-w o`** to close the current window.
- Tabs: Organize windows into tabs.
  - Example: **`:tabnew filename`** to open a file in a new tab, **`gt`** to switch to the next tab, **`gT`** to switch to the previous tab.

### Search and Replace with Regular Expressions

- **Search**: Press `/` to search forward and `?` to search backward.
  - Example: **`/pattern`** to search for "pattern", `\b` represents border, `\bword\b means that precisely matches the **word**.
  
    ```vim
    /\bword\b <=> /\<word\>
    ```
  
- **Advanced Search**: Use regular expressions to perform complex searches.
  - **Example**: **`/\v(pattern1|pattern2)`** to search for "pattern1" or "pattern2".
- **Replace with Confirmation**: Use **`c`** to confirm each replacement.
  - **Example**: **`:%s/old/new/gc`**.

- `/` string will let you search forward through a file for string
- `?` string will let you search backward through a file for string
- `*` will search for the word the cursor is on
- `n` will take you to the next instance (if any)
- `p` will take you to the previous instance (if any)
  - Vim will say “search hit TOP, continuing at BOTTOM” or similar when you’ve looped around
- `:s/string/newstring/` will replace string on its current line.
- `:s/string/newstring/g` will replace string globally.
- `:s/string/newstring/gc` will confirm before replacing string globally.
- Use \ to escape the / character if you want to search and replace it.
  - If you wanted to replace `/etc/filename` in a doc with `/etc/newfile` you’d use `:s/\/etc\/filename/\/etc\/newfile/gc`

### Using External Commands

- **Run Shell Commands**: Use **`:!`** to run external commands.
  - **Example**: **`:!ls`** to list files in the current directory.
- **Read Command Output**: Use **`:r !`** to read the output of a command into the current buffer.
  - **Example**: **`:r !ls`** to insert the directory listing into the buffer.

### Autocommands and Filetype Plugins

- **Autocommands**: Execute commands automatically in response to events.
  - **Example**: **`:autocmd BufRead,BufNewFile *.md set filetype=markdown`** to set the file type to Markdown for **`.md`** files.
- **Filetype Plugins**: Enable filetype-specific settings and plugins.
  - **Example**: **`filetype plugin on`** in your **`.vimrc`**.

### Scripting and Custom Functions

- **Vimscript**: Write custom scripts and functions to extend Vim.
  - **Example**: Define a custom function in your **`.vimrc`**:
  
    ```vim
    function! MyFunction()
        echo "Hello, Vim!"
    endfunction
    command! Hello call MyFunction()
    ```
  
  - Use **`:Hello`** to call the custom function

### Advanced Navigation

- **Marks**: Set marks to jump between specific positions.
  - **Example**: **`ma`** to set mark **`a`**, ``a`` to jump to mark **`a`**.
- **Jump Lists**: Navigate through the list of positions you've jumped to.
  - **Example**: **`Ctrl-o`** to go to the previous position, **`Ctrl-i`** to go to the next position.
- **Tag Navigation**: Use tags to navigate code.
  - **Example**: Generate tags with **`ctags`**, then use **`:tag tagname`** to jump to a tag.
  
```txt

:marks
mark line  col file/text
 '      4    0 Mark 5.00 20 
 a      4    5 Mark 5.00 20 
 f      4    0 Mark 5.00 20 
 0      4   29 ~/Desktop/texts.txt
 1      2    0 ~/Desktop/texts.txt
 2      2    0 ~/Desktop/texts.txt
 3      5   27 ~/Desktop/texts.txt
 4      5   27 ~/Desktop/texts.txt
 5      3   17 ~/Desktop/texts.txt
 6      3   17 ~/Desktop/texts.txt
 7      3   17 ~/Desktop/texts.txt
 8      3   17 ~/Desktop/texts.txt
 9      5    4 ~/Desktop/texts.txt
 "      1    0 Beth 4.00 0 
 [      1    0 Beth 4.00 0 
 ]      6    0 Susie 4.25 18
 ^      3   14 Kathy 4.00 1000 
 .      3   13 Kathy 4.00 1000 
```

|symbol|description|
|--|--------|
|`.`|the last position a change was made. The usage: (1), <u>'.</u>; (2), <u>`.</u>|
|`[`|it's the first character in the text that has been changed or yanked. The usage: (1), <u>'[</u>; (2), <u>`[</u>
|`]`|it's the last character in the text. The usage: (1), <u>']</u>; (2), <u>`]</u>|
|`“`|the last position of the cursor when you exited the previous Vim session. The usage: (1), <u>'"</u>; (2), <u>`"</u>|
|`'`|The usage: (1), <u>''</u>; (2), <u>`'</u>|

Those marks in the table above are present whether you’ve set any marks manually or not. The `[` and `]` marks indicate the last changed or copied (“yanked”) text.

### Registers and Macros

- **Registers**: Vim has multiple registers for copying and pasting. Use **`"`** followed by the register name to specify a register.
  
  There are 9 options about register. **Example**: **`"aY`** to yank (copy) into register **`a`**, and **`"ap`** to paste from register **`a`**.
  - named register
  
    - Registers `"a` to `"z` are named registers. You can use them to store text temporarily.
    - Lowercase letters (a to z) replace the contents of the register.
    - Uppercase letters (A to Z) append to the contents of the register.
    - Yanking and Pasting:

      - `"ayy`: Yanks the current line into register `a`.
      - `"Ayy`: Appends the current line to the contents of register `a`.
      - `"ap`: Pastes the contents of register `a`.
    - Visual Mode Operations:

      Enter visual mode with `v`, select the text, and use `"ay` to yank the selection into register 'a'.
    - Paste from register a with "ap.
    - Special Register Operations:

      The > flag in 'cpoptions' (if set) inserts a line break before appending text with uppercase registers.

      Copy a Word into Register c:
    - For example:
  
      1. Copy a Word into Register c:
  
          Move the cursor over a word and yank it:
  
          ```vim
          "cyiw
          ```
  
      2. Move to Another Word and Append it to Register c:
  
          Move the cursor over another word and append it:
  
          ```vim
          "Cyiw
          ```

      3. Paste the Contents of Register c:

          ```vim
          "cp
          ```

  - unnamed register
    1. Filling the Unnamed Register:

       - The unnamed register ("") automatically stores the text that is deleted using the d, c, s, or x commands, or copied using the y command.
       - This occurs even if a specific register was used. For example, d, c, s, x, and y will all update the unnamed register.
  
    2. Accessing the Unnamed Register:

       - The unnamed register can be accessed explicitly using "", which requires typing two double quotes.
       - When using the p or P commands to paste, Vim uses the unnamed register by default if no specific register is specified.
    3. Exceptions:

       - The _ (black hole) register: Text deleted with "_dd does not update the unnamed register or any other register.

  - other classes refer to [here](https://vimdoc.sourceforge.net/htmldoc/change.html#registers)

- **Macros**: Record a sequence of commands for repeated use.
  - **interpretation**: Press **`q`**, followed by a register name (e.g., **`q`**), perform your commands, and press **`q`** again to stop recording. Replay the macro with **`@`** followed by the register name.

  - **`Practical Examples`**

    ```txt
    Line 1
    Line 2
    Line 3
    Line 4
    ```

    Example 1: Recording a Simple Macro.

    1. Start Recording:
        - Press qa to start recording into register a.
    2. Perform Commands:

        - press `j` to move to the next line;
        - press `dd` to delete the line;
        - press `j` to move to the next line.
    3. Stop Recording:(fdl (f j k e z)jlda)

        - Press q to stop recording.
    4. Replay the Macro:

        - press `gg` to Move to the top of the file
        - Press `@a` to replay the macro. This will move to the next line, delete it, and move to the next line again.
    
    Example 2: Applying a Macro Multiple Times
    1. Replay the Macro Multiple Times:
         - You can replay the macro multiple times by specifying a count before `@`.
         - For example, to replay the macro stored in register `a` 3 times, press `3@a`.
    
    **Example Workflow**
    1. Open a file in Vim:

        ```shell
        vim example.txt
        ```
    2. Start Recording into Register a:

        ```vim
        qa
        ```
    3. Perform the Commands:

        - press `j` (move to the next line)
        - press `dd`  (delete the current line)
        - press `j` (move to the next line)
    4. Stop Recording:

        ```vim
        q
        ```
    5. Replay the Macro:

       - Press `gg` to move to the top of the file.
       - Press `@a` to replay the macro once, or `3@a` to replay it three times.

---

**question 1**: what is the current file name in vim

- Command Mode: Type `:f` or `:file` in command mode. This will display the name of the current file.
- Command Mode with Full Path: Press `1` and then `Ctrl-G` to display the full path of the current file.
- Insert Mode: In insert mode, type `Ctrl-R` then `%` to insert the name of the current file into your document.
- Status Line: You can also set the status line to always display the current file name. Add the following lines to your .vimrc file:
  
  ```txt
  set laststatus=2
  set statusline=%F
  ```
  
The %F will be replaced with the full path to the current file