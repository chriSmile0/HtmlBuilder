# HTMLBuilder

## Why ? 
Create a tool for create html page with a file or one line 
with a simple system of parse line and inheritance.   
Many Framework demand to write the classic tag line for create 
the page.  
We suggest to delete the '<>' use for more comprehension and 
more accessibility.  
The inheritance is replace by '{}' and the tabulations and the level of 
any block is create by the inline or not inline level.

## For Who ? 
- For command line user
- For the user don't want to write in Web languages -> Write a file with many specifics tags and the tool create the html file

## Version 

### V1.8 
Possibility to update a css file with css intructions 
Example : 
- File(css) v1: 
	```
	* {margin:auto;}
	```
- File(css) v2:
	```
	* {
		margin:auto;
	}
	```
- File(modification_file) : 
	```
	* margin=10px|color=black
	```
- result.css : 
  	```
	* {
		margin:10px;
		color:black;
	}
	```
- **Rules:**<br> 
	- Css file structure is like v1 or v2 in V1.8 section not another form 
- [x] Update and Create style Implementation



### V2 -> Future Version
- Combine version to create tags and add content and style in the creation 
  process


## Build and Exec (V1)
### Construction 
	./htmlbuilder --ts --d
	./htmlbuilder --ts --d page.html
	./htmlbuilder --ts -c
	./htmlbuilder --ts -c page.html
	./htmlbuilder --ts -l "article;p"
	./htmlbuilder --ts -l "article;p" page.html
	./htmlbuilder --ts -f ../build_lines 
	./htmlbuilder --ts -f ../build_lines page.html

### Modification 
	./htmlbuilder --mf --d page.html
	./htmlbuilder --mf -c page.html
	./htmlbuilder --mf -l "1p paragraphe" ../page.html
	./htmlbuilder --mf -f ../modif_lines page.html

### Modification Style 
	./htmlbuilder --sy --d page.html style.css
	./htmlbuilder --sy -c page.html style.css
	./htmlbuilder --sy -l "1p id=ID" page.html style.css
	./htmlbuilder --sy -f ../style_lines page.html style.css

### Update Style in Css file
	./htmlbuilder --usy -f ../update_style ../style_inh.css

### MakeTarget 
**Test: ->NB : {option1/option2}=correct options**   
    `make test OPT0=--{ts/mf/sy} OPT1=-{-d/c/l/f} ARG1={""/p.html/"line"/file} ARG2={""/p.html} ARG3={""/s.css}`

**Others tests:**
- **testconstruction**  
	`make test OPT=-{-d/c/l/f} ARG1={""/p.html/"line"/file} ARG2={""/p.html}`
- **testmodifcation**  
	`make test OPT=-{-d/c/l/f} ARG1={""/p.html/"line"/file} ARG2={""/p.html}`
- **testmodifcationstyle**   
	`make test OPT=-{-d/c/l/f} ARG1={""/p.html/"line"/file} ARG2={""/p.html} ARG3={""/s.css}`

**Examples:**
- `make testconstruction OPT=-l ARG1="article\;p" ARG2=../test/page.html`
- `make testmodification OPT=-f ARG1=../modif_lines ARG2=page.html`
- `make testmodification OPT=-l ARG1="1p paragraphe\;1span spa" ARG2=page.html`
- `make testmodificationstyle OPT=-f ARG1=../style_lines ARG2=../page.html ARG3=../style.css`
- `make testmodificationstyle OPT=-l ARG1="1p id=ID\|class=classe\;1span class=classe" ARG2=../page.html ARG3=../style.css` 
- `make testupdatestyle OPT=-f ARG1=../update_style ARG2=../style_inh.css`

## Features 

## Conclusion 