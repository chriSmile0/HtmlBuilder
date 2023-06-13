# BotBuildHtml

## Objectifs 
Construire de manière très rapide une page html avec seulement des balises en entrée.  

## Construction 

## Modification 
On cherche maintenant à modifier le contenu de nos balises 
On doit pour cela pouvoir : 
- [ ] Définir le format de modification par exemple : `p1 paragraphe`
      serais une solution intéressante qui signifie que le premier paragraphe
      qui apparait dans mon fichier doit se voir ajouter le contenu `paragraphe`
- [x] Pouvoir insérer une ligne dans un endroit précis du fichier 
- [ ] Automatiser la chose dans un fichier ou en ligne de commande 
      ou avec l'option -l (pas très efficace ni durable)


### V1 -> Spec 
Définition et implémentation du format et sa prise en compte dans l'exec


## Ajouts et améliorations possibles 
- [x] Au final on sera sur la création de code objet qui stockera la ligne de 	chaque objet et sous-objets concernées.  
- [ ] Chacun possède donc un id afin de le modifier plus tard.  
  On aura donc une table de correspondance id,objet trié de manière croissante en termes de ligne.  
- [ ] Chaque objet sera donc modifiable. Mais à chaque modification on est forcé de réécrire tout  le fichier , ce qui pose des problèmes donc faut mieux avoir l'idée de l'objet fini dès la première exec.
  
- [ ] On aura donc 2 modes , celui pour construction et celui pour modfication 


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
	make test ARG=1-f ARG2=file
	make test ARG=1-l ARG2={article\;p}
	make test ARG=1-c 
	make test ARG=1--d 
	
### Modification 
	make test ARG=1-f ARG2=file ARG3=file.html
	make test ARG=1-l ARG2="1p\ paragraphe" ARG3=file.html
	make test ARG=1-c ARG2=file.html 
	make test ARG=1--d ARG2=_

## Conclusion 