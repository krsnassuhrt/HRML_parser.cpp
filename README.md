- Parses nested HRML tags
- Supports multi-attribute lookup
- Uses stack + unordered map

Sample Input

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value

Sample Output

Name1
Not Found!
HelloWorld



first problem faced was to add tag in stack and reverse it inorder to make it tag1.tag2.tag3 path , also keeping in mind not to add extra dot in end
another problem was the space in between within the opening tags , also to keep in min different cases if there are multiiple attributes
these two were the major problems and headache for me

but i learned or i say experienced the importance of solving problem layer by layer rather looking it as a whole.
