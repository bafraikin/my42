//= require jquery-3.3.1

var sum = function(a,b) {
  return (Number(a) + Number(b));
}

var substract = function(a,b) {
  return (Number(a) - Number(b));
}

var multiply = function(a,b) {
  return (Number(a) * Number(b));
}

var divide = function(a,b) {
  return (Number(a) / Number(b));
}

var affiche = function(chara) {  //rajoute un charactere à l'ecran
  let ecr = $("#ecran");
  ecr[0].value = ecr[0].value + chara;
}

var cell = function() {  //supprime ce qu'il y a l'ecran
  $('#ecran')[0].value = " ";
}

var appli = function(chara, chiff1, chiff2) { //simplifie la lecture de evalxpr

  return (fucktion[array.indexOf(chara)](chiff1, chiff2));
}

var goodindex = function(tab) {  //n'existe que pour evalxpr

  let min = null;
  let mult = 0;
  let div = 0;
    mult = tab.indexOf("*");
    div = tab.indexOf("/");

  if ( mult != -1)
    min = mult;
  if (div >= 0 && min == null)
    min = div;
  if (mult > div && div >= 0 )
    min = div;
  if (min == null)
    min = 0;

console.log(min);
  return (min);
}

var evalexpr = function(str) {  //cette fonction va gerer les priorité

  let index = 0
  let result = 0
  let chiffre = str.match(/\d+\.?\d*/g);
  let operateur = str.match(/[\+\-\*\/]/g);
  if (operateur.includes("*") || operateur.includes("/")) {
    while (1 < chiffre.length) {

      index = goodindex(operateur);
      result = appli(operateur[index], chiffre[index], chiffre[index+1]);
      operateur.splice(index,1);
      chiffre.splice(index,2,result);
    }
    return (result);
  }
  else {
    while (index < operateur.length) {
      result = appli(operateur[index], chiffre[0], chiffre[1]);
      chiffre.splice(0,2,result);
      index++;
    }
    return (result);
  }
}

var calcul = function () {  // fonction qui calcul simplement
  //ecr[0].value = (eval(ecr[0].value));

  let regex = /\d+\.?\d*(\s\W\s\d+\.?\d*)*/g;
  let reg = /\d+\.?\d*/g
  let ecr = $("#ecran");
  let funct = 0;
  str = ecr[0].value;
  if (str.match(regex))
    if ( str.match(reg).length == 2 ) {
      funct = array.indexOf(str.match(/[\-\+\*\/]/g)[0]);
      ecr[0].value = fucktion[funct](str.match(reg)[0], str.match(reg)[1]);
    }
  else {
    ecr[0].value = evalexpr(ecr[0].value);
  }
  else {
    alert("erreur dans le calcul envoyé");
  }
}

let operat = [" + ", " - ", " x ", " / "];
let array = ["+", "-", "*", "/"];
let fucktion = [sum,substract,multiply, divide];
let chiffre = 9;
let ligne = 0
let index = 1
let classname =  "" ;

c = document.createElement('ul');
$(c).attr('id', 'calculette')

$("body").append(c);
$("body")[0].onkeypress = function(value) {
  if( value.key == "Enter" )
    calcul();
}

pe = document.createElement('input');
$(pe).appendTo('#calculette')
  .attr('id', 'ecran')

c = document.createElement('ul');
$(c).appendTo('#calculette')
  .attr('id', 'operateur')


while (ligne < operat.length) {

  c = document.createElement('li');
  if(operat[ligne] === " x ") {
    $(c).appendTo("#operateur")
      .html(operat[ligne])
      .click(function() {
        affiche(" * ");
      })
  }
  else {
    $(c).appendTo("#operateur")
      .html(operat[ligne])
      .click(function() {
        affiche($(this)[0].innerHTML);
      })
  }
  ligne++;
}

while (chiffre >= 1) {
  ligne = 0
  classname = "class" + index;
  al = document.createElement('ul');
  $(al).addClass(classname)
    .appendTo('#calculette')
  while (ligne < 3 && chiffre >= 0 ) {
    d = document.createElement('li');
    $(d).addClass(classname)
      .html(chiffre)
      .appendTo($(al))
      .click(function() {
        affiche($(this)[0].innerHTML);
      })
    ligne++;
    chiffre--;
  }
  index++;
}

al = document.createElement('ul');
$(al).addClass("last")
  .appendTo('#calculette')
d = document.createElement('li');
$(d).html(0)
  .appendTo($(al))
  .click(function() {
    affiche($(this)[0].innerHTML);
  })
d = document.createElement('li');
$(d).addClass(classname)
  .html(".")
  .appendTo($(al))
  .click(function() {
    affiche($(this)[0].innerHTML);
  })

d = document.createElement('li');
$(d).addClass(classname)
  .html("AC")
  .appendTo($(al))
  .click(function() {
    cell();
  })
d = document.createElement('li');
$(d).addClass(classname)
  .html("=")
  .appendTo($(al))
  .click(function() {
    calcul();
  })
