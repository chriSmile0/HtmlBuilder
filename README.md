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
	./htmlbuilder -f 
	./htmlbuilder -l
	./htmlbuilder -c
	./htmlbuilder --d 

### Modification 
	./htmlbuilder -f file file.html
	./htmlbuilder -l "1p\ paragraphe" file.html
	./htmlbuilder -c file.html
	./htmlbuilder --d _

### Construction 
	make test ARG1=-f ARG2=file
	make test ARG1=-l ARG2={article\;p}
	make test ARG1=-c 
	make test ARG1=--d 
	
### Modification 
	make test ARG1=-f ARG2=file ARG3=file.html
	make test ARG1=-l ARG2="1p\ paragraphe" ARG3=file.html
	make test ARG1=-c ARG2=file.html 
	make test ARG1=--d ARG2=_

## Conclusion 