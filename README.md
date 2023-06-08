# BotBuildHtml

## Objectifs 
Construire de manière très rapide une page html avec seulement des balises en entrée.  

## Construction 

### V5 -> Spec
Pour le moment on ne prends en compte que certaines balises 
On peut maintenant toutes les ajoutées 
Cependant elles se trouvent en 2 catégories, ce sont les inlines et les non 
inline.   
**_Exemple :_**

**_Inline_** -> 
`div span` : 

	<div><span></span>
	</div>

**_No_Inline_** -> 
`div p` : 

	<div>
		<p>
		</p>
	</div>

Le <b>span</b> doit donc se tenir sur une ligne et ne pas provoquer de saut de ligne après sa fin de balise 

### V6 -> À spécifier 


## Modification 
- [x] Au final on sera sur la création de code objet qui stockera la ligne de 	chaque objet et sous-objets concernées.  
- [ ] Chacun possède donc un id afin de le modifier plus tard.  
  On aura donc une table de correspondance id,objet trié de manière croissante en termes de ligne.  
- [ ] Chaque objet sera donc modifiable. Mais à chaque modification on est forcé de réécrire tout  le fichier , ce qui pose des problèmes donc faut mieux avoir l'idée de l'objet fini dès la première exec.
  
- [ ] On aura donc 2 modes , celui pour construction et celui pour modfication 


## Conclusion 