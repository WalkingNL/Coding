

---
- B*       matches the null string or B or BB, and so on
- AB*C     matches AC or ABC or ABBC, and so on
- AB+C     matches ABC or ABBC or ABBBC, and so on
- ABB*C    also matches ABC or ABBC or ABBBC, and so on
- AB?C     matches AC or ABC
- [A-Z]+   matches any string of one or more upper-case letters
- (AB)+C   matches ABC, ABABC, ABABABC, and so on

---



---

/^[0-9]+$/ 
  matches any input line that consists of only digits

/^[0-9][0-9][0-9]$/ 
  exactly three digits

/^([+-])?[0-9]+[.]?[0-9]*$/ 
  a decimal number with an optional sign and optional fraction

/^[+-]?[0-9]+[.]?[0-9]*$/ 
  also a decimal number with an optional sign and optional fraction

/^[+-]?([0-9]+[.]?[0-9]*|[eE][+-]?[0-9]+)?$/ 
  a floating point number with optional sign and optional exponent

/^[A-Za-z][A-Za-z0-9]*$/ 
  a letter followed by any letters or digits (e.g., awk variable name)

/^[A-Za-z]\$|^[A-Za-z][0-9]$/ 
  a letter or a letter followed by a digit (e.g., variable name in Basic)

/^[A-Za-z][0-9]?$/ 
  also a letter or a letter followed by a digit


---

---
TABLE 2-2. ESCAPE SEQUENCES
|SEQUENCE|MEANING|
|--|--|
|\b|backspace|
|\f|formfeed|
|\n|newline (line feed)|
|\r|carriage return|
|\t|tab|
|\ddd|octal value ddd, where ddd is 1 to 3 digits between 0 and 7|
|\c|any other character c literally (e.g., \\ for backslash, \" for ")|


---


---

|EXPRESSION | MATCHES |
|--|--|
|c|the nonmetacharacter c|
|\c|escape sequence or literal character c|
|^|beginning of string|
|$|end of string |
|.|any character|
|[c1c2...]|any character in c1c2...|
|[^c1c2...]|any character not in c1c2...|
|[c1-c2]|any character in the range beginning with c1 and ending with c2|
|^[c1-c2]|any character not in the range c1 to c2|
|r1\|r2|any string matched by r1 or r2|
|(r1)(r2)|any string xy where r1 matches x and r2 matches y; parentheses not needed around arguments with no alternations|
|(r)*|zero or more consecutive strings matched by r|
|(r)+|one or more consecutive strings matched by r|
|(r)?|zero or one string matched by r|
|(r)|parentheses not needed around basic regular expressions|
|r|any string matched by r|


---
```shell
BEGIN {
    sign = "[+-]?"
    decimal = "[0-9]+[.]?[0-9]*"
    fraction = "[.][0-9]+"
    exponent = "([eE]" sign "[0-9]+)?"
    number = "^" sign "(" decimal "|" fraction ")" exponent "$"
}
$0 ~ number
```

|CLASS|MATCHES	EQUIVALENT EXPRESSION|
|--|--|
|.|anything except newline [^\n\r]|
|\w|word character [a-zA-Z0-9_]|
|\W|non-word character [^\w]|
|\d|digits [0-9]|
|\D|non-digits [^\d]|
|\s|space, tab, newlines [\t\r\n\f]|
|\S|non whitespace characters [^\s]|

`awk` do not support these classes, `\w` is equal to `[w]` in awk, other character with `\` is also like this.


|QUANTIFIER|MATCHES|
|--|--|
|*|0 or more|
|?|0 or 1|
|+|1 or more|
|{n}|exactly n times|
|{n, }|n or more times|
|{n, m}|n to m times inclusive|

---

### How to reference capture groups

```shell
 % echo "this is power" | sed -E 's/(this) is power/this is \1 power/' 
```
the result: this is **this** power. The bold part of the output is the replaced part using `\1`

```shell
echo "Python is the best but Python" | sed -E 's/(Python) is the best but \1/\1 is amazing/g'
```
the first `\1` is not work, this command will be changed, like below:
```shell
echo "Python is the best but Python" | sed -E 's/(Python) is the best but Python/\1 is amazing/g'
```

```shell
awk '$0 ~ /GREP/' texts.txt | sed -E 's/Henlo ([0-9]+)/hello \1/g'
```
texts.txt
```txt
HelloHello rand chars World 56 rand chars
 chars
GREP rand chars  chars
 chars
GREP rand chars  chars
```
### Lookarounds
|OPERATION|REGEX|
|--|--|
|positive lookahead|(?=C)X|
|negative lookahead|(?!C)X|
|positive lookbehind|`(?<=C)X` or `X(?<=C)`|
|negative lookbehind|`(?<!C)X` or `X(?<!C)`|

`(?=.*linux)GNU` and `GNU(?=.*linux)`

`(?<=GNU.*)linux` and `linux(?<=GNU.*)`
> note that the position of `.*` is different between lookahead and lookbehind.


qabilgong@gmail.com
932382981@qq.com
qabil0581@GMAIL.COM
qdfz*fkl@163.com
qafj-fdk@one.com
qabil_32@gmail.com

12345687330
13243aaBB
132_r3u2
32345riq
abAkd139
*72)32AHLJc

---
practical use:
```
Email box: ^[^@\s\*\-\.]+@[a-zA-Z0-9_]+\.\w+
```

We will create a regex which imposes the following criteria:

- Minimum 8 characters and maximum 16 characters.
- At least one lower case letter.
- At least one upper case letter.
- At least one number.

To achieve this, you can use positive lookaheads. This is the regex:
```
passcode: (a-z)+(A-Z)+(0-9)+{6,18}

^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,16}$
```
---
Example 3. (1), converting the first character of each word into uppercase if it is lowercase; (2), converting the rest part of each word into lowercase if it is uppercase. 
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

Let's take an example string to see how this works:

    hello WORLD
Applying the Regular Expression

`\v<`: This matches the start of a word. `.`: The first character of the word (h in hello and W in WORLD). `(\w*)`: The remaining characters of the word (ello in hello and ORLD in WORLD).

So, when applied to hello:

h is captured by the first group `(.)`.
ello is captured by the second group `(\w*)`.
Similarly, for WORLD:

W is captured by the first group `(.)`.
ORLD is captured by the second group `(\w*)`.

Replacement

`\u\1`: Converts the first captured group to uppercase.

`\L\2`: Converts the second captured group to lowercase.

Result

For hello:

\u\1 converts h to H.

\L\2 converts ello to ello.

For WORLD:

\u\1 converts W to W.

\L\2 converts ORLD to orld.

Final Transformation

    Hello World

---