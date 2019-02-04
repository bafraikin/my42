
var myMax = function(array) {

  var index = 0;
  var max = array[0];
  while (index < array.length) 
  {
    if (array[index] > max )
    {
      max = array[index];
    }
    index++;
  }
  return(max);
}

var voyelCount = function(string) {

  let regex = /[aeiouy]/ig;
  let count = string.match(regex).length
  return(count);
}

var reverse = function(string) {
  return(string.split("").reverse().join(""));
}

let tableau = [1,2,3,4,5,6,7,8,9,50,10,20];
let string = "Mango Ananas BEbe" //je compte les majuscules

document.getElementById("demo").innerHTML = "Le plus grand chiffre dans mon tableau c'est " + myMax(tableau);
document.getElementById("coucou").innerHTML = "Le nombre de voyelle c'est " + voyelCount(string);
document.getElementById("trois").innerHTML = 'la meme phrase inversé donne ' + reverse(string);
