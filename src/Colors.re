open Colors_Utils;

type color =
  | Red
  | Yellow
  | Green
  | Blue
  | White
  | Cyan
  | Magenta
  | BgBlack
  | BgRed
  | BgGreen
  | BgYellow
  | BgBlue
  | BgMagenta
  | BgCyan
  | BgWhite
  | BgRedBright
  | BgGreenBright
  | BgYellowBright
  | BgBlueBright
  | BgMagentaBright
  | BgCyanBright
  | BgWhiteBright;

type modifier =
  | Reset
  | Bold
  | Dim
  | Italic
  | Underline
  | Inverse
  | Hidden
  | Strikethrough;

type keywordOptions = {
  colorType: color,
  word: string
};

let changeColor = (c, str) =>
  switch c {
  | Red => Colors_Utils.red(str)
  | Yellow => Colors_Utils.yellow(str)
  | Green => Colors_Utils.green(str)
  | Blue => Colors_Utils.blue(str)
  | Magenta => Colors_Utils.magenta(str)
  | Cyan => Colors_Utils.cyan(str)
  | White => Colors_Utils.white(str)
  | BgBlack => Colors_Utils.bgBlack(str)
  | BgRed => Colors_Utils.bgRed(str)
  | BgGreen => Colors_Utils.bgGreen(str)
  | BgYellow => Colors_Utils.bgYellow(str)
  | BgBlue => Colors_Utils.bgBlue(str)
  | BgMagenta => Colors_Utils.bgMagenta(str)
  | BgCyan => Colors_Utils.bgCyan(str)
  | BgWhite => Colors_Utils.bgWhite(str)
  | BgRedBright => Colors_Utils.bgRedBright(str)
  | BgGreenBright => Colors_Utils.bgGreenBright(str)
  | BgYellowBright => Colors_Utils.bgYellowBright(str)
  | BgBlueBright => Colors_Utils.bgBlueBright(str)
  | BgMagentaBright => Colors_Utils.bgMagentaBright(str)
  | BgCyanBright => Colors_Utils.bgCyanBright(str)
  | BgWhiteBright => Colors_Utils.bgWhiteBright(str)
  };

let modify = (m, str) =>
  switch m {
  | Reset => Colors_Utils.reset(str)
  | Bold => Colors_Utils.bold(str)
  | Dim => Colors_Utils.dim(str)
  | Italic => Colors_Utils.italic(str)
  | Underline => Colors_Utils.underline(str)
  | Inverse => Colors_Utils.inverse(str)
  | Hidden => Colors_Utils.hidden(str)
  | Strikethrough => Colors_Utils.strikethrough(str)
  };

let changeKeyword = (keyword, str, color) => {
  let containsString = Js.String.includes(keyword, str);
  containsString ?
    Js.String.replace(keyword, changeColor(color, keyword), str) : str;
};

let doColorChange = (color, keywordOptions, str) =>
  switch color {
  | Some(c) =>
    switch keywordOptions {
    | Some({word}) =>
      /* Only change the strings which arent keyword */
      Js.String.split(" ", str)
      |> Js.Array.map(x => x === word ? x : changeColor(c, x))
      |> Js.Array.joinWith(" ")
    | None => changeColor(c, str)
    }
  | None => str
  };

let doModifier = (modifier, str) =>
  switch modifier {
  | Some(m) => modify(m, str)
  | None => str
  };

let highlightKeyword = (options, str) =>
  switch options {
  | Some({colorType, word}) => changeKeyword(word, str, colorType)
  | None => str
  };

let changeBackground = (c, str) =>
  switch c {
  | Red => Colors_Utils.bgRed(str)
  | Yellow => Colors_Utils.bgYellow(str)
  | Green => Colors_Utils.bgGreen(str)
  | Blue => Colors_Utils.bgBlue(str)
  | Magenta => Colors_Utils.bgMagenta(str)
  | Cyan => Colors_Utils.bgCyan(str)
  | White => Colors_Utils.bgWhite(str)
  | BgBlack => Colors_Utils.bgBlack(str)
  | BgRed => Colors_Utils.bgRed(str)
  | BgGreen => Colors_Utils.bgGreen(str)
  | BgYellow => Colors_Utils.bgYellow(str)
  | BgBlue => Colors_Utils.bgBlue(str)
  | BgMagenta => Colors_Utils.bgMagenta(str)
  | BgCyan => Colors_Utils.bgCyan(str)
  | BgWhite => Colors_Utils.bgWhite(str)
  | BgRedBright => Colors_Utils.bgRedBright(str)
  | BgGreenBright => Colors_Utils.bgGreenBright(str)
  | BgYellowBright => Colors_Utils.bgYellowBright(str)
  | BgBlueBright => Colors_Utils.bgBlueBright(str)
  | BgMagentaBright => Colors_Utils.bgMagentaBright(str)
  | BgCyanBright => Colors_Utils.bgCyanBright(str)
  | BgWhiteBright => Colors_Utils.bgWhiteBright(str)
  };

let applyBackgroud = (bg, str) =>
  switch bg {
  | Some(b) => changeBackground(b, str)
  | None => str
  };

let colors = (~color=?, ~bg=?, ~modifier=?, ~keywordOptions=?, str) => {
  let modifyStr =
    highlightKeyword(keywordOptions, str)
    |> doModifier(modifier)
    |> doColorChange(color, keywordOptions)
    |> applyBackgroud(bg);
  modifyStr;
};