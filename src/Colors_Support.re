let notFoundStr = "NOT_FOUND";

let safeGetEnv = str =>
  try (Sys.getenv(str)) {
  | Not_found => notFoundStr
  };

let getOS = () => Sys.os_type;

/* TODO: Sort out the terminal colors for different node versions */
let isWindowsColorTerm = () => getOS() === "Win32" ? 1 : 0;

let isTerminal256 = () => {
  let termEnv = safeGetEnv("TERM");
  termEnv !== notFoundStr ?
    {
      let re = [%re "/-256(color)?$/i"];
      let match = Js.String.match(re, termEnv);
      switch match {
      | Some(m) => 2
      | None => 0
      };
    } :
    0;
};

let isFancyTerminal = () => {
  let termEnv = safeGetEnv("TERM_PROGRAM");
  termEnv !== notFoundStr ?
    {
      let version =
        int_of_string(
          Js.String.split(".", safeGetEnv("TERM_PROGRAM_VERSION"))[0]
        );
      switch termEnv {
      | "iTerm.app" => version >= 3 ? 3 : 2
      | "Hyper" => 3
      | "Apple_Terminal" => 2
      | _ => 0
      };
    } :
    2;
};

let isBasicTerminal = () => {
  let termEnv = safeGetEnv("TERM");
  termEnv !== notFoundStr ?
    {
      let re = [%re "/^screen|^xterm|^vt100|^rxvt|color|ansi|cygwin|linux/i"];
      let match = Js.String.match(re, termEnv);
      switch match {
      | Some(m) => 1
      | None => 0
      };
    } :
    0;
};

let isColorTerm = () => safeGetEnv("COLORTERM") !== notFoundStr ? 1 : 0;

let isTeamCityCompatible = () => {
  let termEnv = safeGetEnv("TEAMCITY_VERSION");
  termEnv !== notFoundStr ?
    {
      let re = [%re "/^(9\\.(0*[1-9]\\d*)\\.|\\d{2,}\\.)/"];
      let match = Js.String.match(re, termEnv);
      switch match {
      | Some(m) => 1
      | None => 0
      };
    } :
    0;
};

let isColorCompatibleCi = () => {
  let termEnv = safeGetEnv("CI");
  let colorCIs = ["TRAVIS", "CIRCLECI", "APPVEYOR", "GITLAB_CI"];
  termEnv !== notFoundStr ?
    {
      let arr = Array.of_list(colorCIs);
      let supportedCI = Js.Array.some(x => termEnv === x, arr);
      let isCodeShip = safeGetEnv("CI_NAME") === "codeship";
      supportedCI || isCodeShip ? 1 : 0;
    } :
    0;
};

let supportsColors = () => [
  isColorCompatibleCi(),
  isTeamCityCompatible(),
  isWindowsColorTerm(),
  isColorTerm(),
  isBasicTerminal(),
  isFancyTerminal()
];

let test = supportsColors() |> List.fold_left(Pervasives.max, 0);