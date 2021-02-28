import { text } from "express";

var achtergrondPlaatje;
var laatsteUpdateTimeStamp;
var knikkerkleur
var knikkeraantal

/**
 * preload
 * deze functie wordt als eerste javascriptfunctie uitgevoerd,
 * dus zelfs nog vóór setup() !
 * Gebruik deze functie om plaatjes van de server te laten laden
 * door de browser die je widget opent
 */
function preload() {
  achtergrondPlaatje = loadImage('images/Knikkerbaanfoto.jpg');
}


/**
 * checkForDatabaseUpdate
 * Controleert of de database wijzingen heeft waarvan wij nog niet weten.
 * Verdere actie vereist bij reponse "Update needed"
 */
function checkForDatabaseChanges() {
  // zet het serverrequest in elkaar
  var request = new XMLHttpRequest();
  request.open('GET', `/api/checkchanges/${laatsteUpdateTimeStamp}`, true)
  request.onload = function () {
    if (request.status >= 200 && request.status < 400) {
      if (this.response == "Update needed") {
        console.log("Server geeft aan dat de database een update heeft die widget nog niet heeft");

        // roep ander update functie(s) aan:
        getMarbleCount();
      }
      else {
        // je kunt de code hieronder aanzetten, maar krijgt dan wel iedere seconde een melding
        // console.log("Widget is up to date");
      }
    }
    else {
        console.log("bleh, server reageert niet zoals gehoopt");
        console.log(this.response);
      }
  }

  // verstuur het request
  request.send()
}

/**
 * getTotalPresses
 * Vraagt het totaal aantal buttonPresses op
 */
function getMarbleCount() {
  // zet het serverrequest in elkaar
  var request = new XMLHttpRequest()
  request.open('GET', '/api/getmarblecount', true)
  request.onload = function () {
    var data = JSON.parse(this.response);
    if (request.status >= 200 && request.status < 400) {
      console.log(`Totaal aantal knikkers = ${data.MarbleCount} `);
      numberOfButtonPresses = data.MarbleCount;
      var newTimeStamp = new Date(data.lasttimestamp).getTime()+1;

      // update indien nodig de timestamp
      if (laatsteUpdateTimeStamp < newTimeStamp) {
        laatsteUpdateTimeStamp = newTimeStamp;
      }
      
    }
    else {
        console.log("bleh, server reageert niet zoals gehoopt");
        console.log(this.response);
      }
  }

  // verstuur het request
  request.send()
}


/**
 * setup
 * de code in deze functie wordt eenmaal uitgevoerd,
 * als p5js wordt gestart
 */
function setup() {
  // Maak het canvas van je widget
  createCanvas(1920, 1080);

  // zet timeStamp op lang geleden zodat we alle recente info binnenkrijgen
  laatsteUpdateTimeStamp = new Date().setTime(0);

  // we vragen elke seconde of er iets is veranderd
  setInterval(checkForDatabaseChanges, 1000);
}


/**
 * draw
 * de code in deze functie wordt meerdere keren per seconde
 * uitgevoerd door de p5 library, nadat de setup functie klaar is
 */
function draw() {

  image(achtergrondPlaatje, 0, 0, 1920, 1080);

  //bovenrand met titel
  rect(0, 0, 1920, 100);
  fill(255, 0, 0);

  textSize(50);
  text('KNIKKERBAAN GROEPJE 3', 1000, 25);
  fill(0, 0, 0);

  //onderrand met namen
  rect(0, 980, 1920, 100);
  fill(255, 0, 0);

  textSize(50);
  text('GEMAAKT DOOR: CHARLIE, DANIELLE, JASMIJN, LARS, LENNARD, REVENNA, THOMAS');

  //blok voor kleur laatste knikker
  rect(800, 216, 216, 150);
  fill(255, 0, 0);
  knikkerkleur;


  //blok voor aantal knikkers
  rect(800, 648, 216, 150);
  fill(255, 0, 0);
  knikkeraantal;

 }
 