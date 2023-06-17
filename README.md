# BotBuildHtml

## Objectifs 
Construire de manière très rapide une page html avec seulement des balises en entrée.  
Rendre ce contenu modifiable afin d'insérer le contenu "affichables" 

## Construction 

## Modification 
On cherche maintenant à affecter un style à nos balises
On doit pour cela pouvoir : 
- [x] Associer une classe, un id à une balise : `1p id=ID;1p classe=CLASSE`
- [ ] Créer l'entête qui permet d'ajouter le fichier style correspondant : 
	`./htmlbuilder -s page.html style.css`
- [ ] Ajouter le fichier css correspondant aux balises 
		Pour le moment pas d'héritage juste les balises et les classes et id 
		associés.

### V1 -> Spec 
Ajouter un fichier css au fichier html 

### V2 -> 
Associer une classe, un id à une balise

## Ajouts et améliorations possibles 
- [ ] Chacun possède donc un id afin de le modifier plus tard.  
  On aura donc une table de correspondance id,objet trié de manière croissante en termes de ligne.  

## Build and Exec 
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

## Conclusion 