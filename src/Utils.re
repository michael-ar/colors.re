open Styles;

let startWrap = v => {j|\u001b[$v|j} ++ "m";

let endWrap = v => {j|\u001b[$v|j} ++ "m";

module Utils = {
  type t;
  let compose = (f, g, x) => f(g(x));
  let pipe = (f, g, x) => g(f(x));
  let reset = str =>
    startWrap(Styles.reset[0]) ++ str ++ endWrap(Styles.reset[1]);
  let bold = str =>
    startWrap(Styles.bold[0]) ++ str ++ endWrap(Styles.bold[1]);
  let dim = str => startWrap(Styles.dim[0]) ++ str ++ endWrap(Styles.dim[1]);
  let italic = str =>
    startWrap(Styles.italic[0]) ++ str ++ endWrap(Styles.italic[1]);
  let underline = str =>
    startWrap(Styles.underline[0]) ++ str ++ endWrap(Styles.underline[1]);
  let inverse = str =>
    startWrap(Styles.inverse[0]) ++ str ++ endWrap(Styles.inverse[1]);
  let hidden = str =>
    startWrap(Styles.hidden[0]) ++ str ++ endWrap(Styles.hidden[1]);
  let strikethrough = str =>
    startWrap(Styles.strikethrough[0])
    ++ str
    ++ endWrap(Styles.strikethrough[1]);
  let black = str =>
    startWrap(Styles.black[0]) ++ str ++ endWrap(Styles.black[1]);
  let red = str => startWrap(Styles.red[0]) ++ str ++ endWrap(Styles.red[1]);
  let green = str =>
    startWrap(Styles.green[0]) ++ str ++ endWrap(Styles.green[1]);
  let yellow = str =>
    startWrap(Styles.yellow[0]) ++ str ++ endWrap(Styles.yellow[1]);
  let blue = str =>
    startWrap(Styles.blue[0]) ++ str ++ endWrap(Styles.blue[1]);
  let magenta = str =>
    startWrap(Styles.magenta[0]) ++ str ++ endWrap(Styles.magenta[1]);
  let cyan = str =>
    startWrap(Styles.cyan[0]) ++ str ++ endWrap(Styles.cyan[1]);
  let white = str =>
    startWrap(Styles.white[0]) ++ str ++ endWrap(Styles.white[1]);
  let gray = str =>
    startWrap(Styles.gray[0]) ++ str ++ endWrap(Styles.gray[1]);
  let grey = str =>
    startWrap(Styles.grey[0]) ++ str ++ endWrap(Styles.grey[1]);
  let bgBlack = str =>
    startWrap(Styles.bgBlack[0]) ++ str ++ endWrap(Styles.bgBlack[1]);
  let bgRed = str =>
    startWrap(Styles.bgRed[0]) ++ str ++ endWrap(Styles.bgRed[1]);
  let bgGreen = str =>
    startWrap(Styles.bgGreen[0]) ++ str ++ endWrap(Styles.bgGreen[1]);
  let bgYellow = str =>
    startWrap(Styles.bgYellow[0]) ++ str ++ endWrap(Styles.bgYellow[1]);
  let bgBlue = str =>
    startWrap(Styles.bgBlue[0]) ++ str ++ endWrap(Styles.bgBlue[1]);
  let bgMagenta = str =>
    startWrap(Styles.bgMagenta[0]) ++ str ++ endWrap(Styles.bgMagenta[1]);
  let bgCyan = str =>
    startWrap(Styles.bgCyan[0]) ++ str ++ endWrap(Styles.bgCyan[1]);
  let bgWhite = str =>
    startWrap(Styles.bgWhite[0]) ++ str ++ endWrap(Styles.bgWhite[1]);
};