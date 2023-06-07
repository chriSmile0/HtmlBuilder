# BotBuildHtml

## Objectifs 
Construire de manière très rapide une page html avec seulement des balises en entrée.  

## Construction 

### V3 
`"{p {1div {p;p}}}"` -> : 

	<p>
		<div>
			<p></p>
			<p></p>
		</div>
	</p>
**_OU_**  
`"{p {2div {p;p}}}"` -> : 

	<p>
		<div>
			<p></p>
			<p></p>
		</div>
		<div>
			<p></p>
			<p></p>
		</div>
	</p>
**_OU_**   
`"{2section;2article}"` -> : Prochain commit 
	
	<section>
	</section>
	<section>
	</section>

	<article>
	</article>
	<article>
	</article>

### V3.5 -> OK 
Utilisation d'un fichier ou de la console ou directement en paramètre 
de l'éxécutable afin de créer le fichier html.

	./htmlbuilder -f file 
	./htmlbuilder -l {article\;p} 
	./htmlbuilder -c 
**_Via Makefile_** -> 

	make test ARG1=-f ARG2=file
	make test ARG1=-l ARG2={article\;p}
	make test ARG1=-c 

### V4 -> Spec
On cherche maintenant à créer de l'indentation car pour le moment 
`./htmlbuilder -l {article\ p}` a pour résultat : 

	<article>
	<p>
	</p>
	</article>
Et ce que l'on aimerait devrais plutôt ressembler à cela : 

	<article>
		<p>
		</p>
	</article>

### V5 -> À spécifier

## Modification 
- [x] Au final on sera sur la création de code objet qui stockera la ligne de 	chaque objet et sous-objets concernées.  
- [ ] Chacun possède donc un id afin de le modifier plus tard.  
  On aura donc une table de correspondance id,objet trié de manière croissante en termes de ligne.  
- [ ] Chaque objet sera donc modifiable. Mais à chaque modification on est forcé de réécrire tout  le fichier , ce qui pose des problèmes donc faut mieux avoir l'idée de l'objet fini dès la première exec.
  
- [ ] On aura donc 2 modes , celui pour construction et celui pour modfication 


## Conclusion 