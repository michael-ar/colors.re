// Generated by BUCKLESCRIPT VERSION 2.2.0, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Colors_Styles = require("./Colors_Styles.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

function startWrap(v) {
  return "\u001b[" + (String(v) + "") + "m";
}

function endWrap(v) {
  return "\u001b[" + (String(v) + "") + "m";
}

function wrap(param) {
  var exit = 0;
  if (param) {
    var match = param[1];
    if (match) {
      if (match[1]) {
        exit = 1;
      } else {
        var last = match[0];
        var head = param[0];
        return (function (str) {
            return startWrap(head) + (str + endWrap(last));
          });
      }
    } else {
      exit = 1;
    }
  } else {
    exit = 1;
  }
  if (exit === 1) {
    throw [
          Caml_builtin_exceptions.match_failure,
          [
            "Colors_Utils.re",
            7,
            11
          ]
        ];
  }
  
}

function compose(f, g, x) {
  return Curry._1(f, Curry._1(g, x));
}

function pipe(f, g, x) {
  return Curry._1(g, Curry._1(f, x));
}

var reset = wrap(Colors_Styles.Colors_Styles[/* reset */2]);

var bold = wrap(Colors_Styles.Colors_Styles[/* bold */3]);

var dim = wrap(Colors_Styles.Colors_Styles[/* dim */4]);

var italic = wrap(Colors_Styles.Colors_Styles[/* italic */5]);

var underline = wrap(Colors_Styles.Colors_Styles[/* underline */6]);

var inverse = wrap(Colors_Styles.Colors_Styles[/* inverse */7]);

var hidden = wrap(Colors_Styles.Colors_Styles[/* hidden */8]);

var strikethrough = wrap(Colors_Styles.Colors_Styles[/* strikethrough */9]);

var black = wrap(Colors_Styles.Colors_Styles[/* black */10]);

var red = wrap(Colors_Styles.Colors_Styles[/* red */11]);

var green = wrap(Colors_Styles.Colors_Styles[/* green */12]);

var yellow = wrap(Colors_Styles.Colors_Styles[/* yellow */13]);

var blue = wrap(Colors_Styles.Colors_Styles[/* blue */14]);

var magenta = wrap(Colors_Styles.Colors_Styles[/* magenta */15]);

var cyan = wrap(Colors_Styles.Colors_Styles[/* cyan */16]);

var white = wrap(Colors_Styles.Colors_Styles[/* white */17]);

var gray = wrap(Colors_Styles.Colors_Styles[/* gray */18]);

var grey = wrap(Colors_Styles.Colors_Styles[/* grey */19]);

var bgBlack = wrap(Colors_Styles.Colors_Styles[/* bgBlack */20]);

var bgRed = wrap(Colors_Styles.Colors_Styles[/* bgRed */21]);

var bgGreen = wrap(Colors_Styles.Colors_Styles[/* bgGreen */22]);

var bgYellow = wrap(Colors_Styles.Colors_Styles[/* bgYellow */23]);

var bgBlue = wrap(Colors_Styles.Colors_Styles[/* bgBlue */24]);

var bgMagenta = wrap(Colors_Styles.Colors_Styles[/* bgMagenta */25]);

var bgCyan = wrap(Colors_Styles.Colors_Styles[/* bgCyan */26]);

var bgWhite = wrap(Colors_Styles.Colors_Styles[/* bgWhite */27]);

var bgBlackBright = wrap(Colors_Styles.Colors_Styles[/* bgBlackBright */28]);

var bgRedBright = wrap(Colors_Styles.Colors_Styles[/* bgRedBright */29]);

var bgGreenBright = wrap(Colors_Styles.Colors_Styles[/* bgGreenBright */30]);

var bgYellowBright = wrap(Colors_Styles.Colors_Styles[/* bgYellowBright */31]);

var bgBlueBright = wrap(Colors_Styles.Colors_Styles[/* bgBlueBright */32]);

var bgMagentaBright = wrap(Colors_Styles.Colors_Styles[/* bgMagentaBright */33]);

var bgCyanBright = wrap(Colors_Styles.Colors_Styles[/* bgCyanBright */34]);

var bgWhiteBright = wrap(Colors_Styles.Colors_Styles[/* bgWhiteBright */35]);

var Colors_Utils = /* module */[
  /* compose */compose,
  /* pipe */pipe,
  /* reset */reset,
  /* bold */bold,
  /* dim */dim,
  /* italic */italic,
  /* underline */underline,
  /* inverse */inverse,
  /* hidden */hidden,
  /* strikethrough */strikethrough,
  /* black */black,
  /* red */red,
  /* green */green,
  /* yellow */yellow,
  /* blue */blue,
  /* magenta */magenta,
  /* cyan */cyan,
  /* white */white,
  /* gray */gray,
  /* grey */grey,
  /* bgBlack */bgBlack,
  /* bgRed */bgRed,
  /* bgGreen */bgGreen,
  /* bgYellow */bgYellow,
  /* bgBlue */bgBlue,
  /* bgMagenta */bgMagenta,
  /* bgCyan */bgCyan,
  /* bgWhite */bgWhite,
  /* bgBlackBright */bgBlackBright,
  /* bgRedBright */bgRedBright,
  /* bgGreenBright */bgGreenBright,
  /* bgYellowBright */bgYellowBright,
  /* bgBlueBright */bgBlueBright,
  /* bgMagentaBright */bgMagentaBright,
  /* bgCyanBright */bgCyanBright,
  /* bgWhiteBright */bgWhiteBright
];

exports.startWrap = startWrap;
exports.endWrap = endWrap;
exports.wrap = wrap;
exports.Colors_Utils = Colors_Utils;
/* reset Not a pure module */