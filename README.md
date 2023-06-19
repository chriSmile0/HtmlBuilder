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
- For the user of the command line 
- For the user don't want to write in Web languages -> Write a file with many specifics tags and the tool create the html file

## Version 
### V1 
- A 'cut' version to create tags and add content and style separatly
- Excellent for modify a skeleton of html page with our style and our content
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
	./htmlbuilder --mf -l "1p paragraphe" page.html
	./htmlbuilder --mf -f ../modif_lines page.html

### Modification Style 
	./htmlbuilder --sy --d page.html style.css
	./htmlbuilder --sy -c page.html style.css
	./htmlbuilder --sy -l "1p id=ID" page.html style.css
	./htmlbuilder --sy -f ../style_lines page.html style.css

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
- `make testconstruction OPT=-l ARG1="article\;p" ARG2=page.html`
- `make testmodifcation OPT=-f ARG1=../modif_lines ARG2=../page.html`
- `make testmodifcationstyle OPT=-f ARG1=../style_lines ARG2=../page.html ARG3=../style.css`
- `make testmodifcationstyle OPT=-l ARG1="1p id=ID" ARG2=../page.html ARG3=../style.css`


## Features 

## Conclusion 