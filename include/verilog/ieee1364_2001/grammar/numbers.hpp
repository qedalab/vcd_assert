number ::=
decimal_number
| octal_number
| binary_number
| hex_number
| real_number

real_number ::=
unsigned_number . unsigned_number
| unsigned_number [ . unsigned_number ] exp [ sign ] unsigned_number
exp ::= e | E
decimal_number ::=
unsigned_number
| [ size ] decimal_base unsigned_number
| [ size ] decimal_base x_digit { _ }
| [ size ] decimal_base z_digit { _ }
binary_number ::= [ size ] binary_base binary_value
octal_number ::= [ size ] octal_base octal_value
hex_number ::= [ size ] hex_base hex_value
sign ::= + | -
size ::= non_zero_unsigned_number
non_zero_unsigned_number 1 ::= non_zero_decimal_digit { _ | decimal_digit}
unsigned_number 1 ::= decimal_digit { _ | decimal_digit }
binary_value 1 ::= binary_digit { _ | binary_digit }
octal_value 1 ::= octal_digit { _ | octal_digit }
hex_value 1 ::= hex_digit { _ | hex_digit }
decimal_base 1 ::= ’[s|S]d | ’[s|S]D
binary_base 1 ::= ’[s|S]b | ’[s|S]B
octal_base 1 ::= ’[s|S]o | ’[s|S]O
hex_base 1 ::= ’[s|S]h | ’[s|S]H
non_zero_decimal_digit ::= 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
decimal_digit ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
binary_digit ::= x_digit | z_digit | 0 | 1
octal_digit ::= x_digit | z_digit | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
hex_digit ::=
x_digit | z_digit | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
| a | b | c | d | e | f | A | B | C | D | E | F
x_digit ::= x | X
z_digit ::= z | Z | ?