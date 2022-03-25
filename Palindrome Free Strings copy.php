<?php
global $manual_input, $caseNumber, $cases;
$caseNumber = 1;
function input() {
    global $numberOfCases, $manual_input, $cases;
    $str = "";
    if (!$manual_input) {
        $f = fopen( 'php://stdin', 'r' );
        while( $line = fgets( $f ) ) {
            $str .= $line;
        }
        fclose($f);
    }
    else {
        $str = $manual_input;
    }
    
    $t = explode("\n", $str);

    foreach($t as $r) {
        $cases[] = explode(" ",$r);
    }
    $numberOfCases = array_shift($cases)[0];
}

function printCase($result) {
    global $caseNumber;
    echo "Case #$caseNumber: $result\n";
    $caseNumber++;
}

$manual_input="2
9
100??11?00101?0101101???";
main();

function main() {
    global $numberOfCases, $cases;
    input();
    foreach ($cases as $key => $case) { // Cases
        $a = $case[0];
        // Write your code here:
        if ($key%2 == 1) {
            $result = createSubstring(createSolutions($a));
            printCase($result);
        }
    }
}


// your functions:

function sampling($chars, $size, $combinations = array()) {

    # if it's the first iteration, the first set 
    # of combinations is the same as the set of characters
    if (empty($combinations)) {
        $combinations = $chars;
    }

    # we're done if we're at size 1
    if ($size == 1) {
        return $combinations;
    }

    # initialise array to put new values in
    $new_combinations = array();

    # loop through existing combinations and character set to create strings
    foreach ($combinations as $combination) {
        foreach ($chars as $char) {
            $new_combinations[] = $combination . $char;
        }
    }

    # call same function again for the next iteration
    return sampling($chars, $size - 1, $new_combinations);

}

function createSolutions($df) {
    $s = [];
    $input = str_split($df);
    $chars = array('1', '0');
    $countSymbol = array_count_values($input)["?"];
    $output = sampling($chars, $countSymbol);
    $result = $input;

    foreach ($output as $key => $val) { // Gibt alle Möglichkeiten der Reihenfolge als String wieder
        foreach(str_split($val) as $bb) { // $bb sind immer ein Zeichen aus einer Möglichkeit von der Reihenfolge
            for ($i=0;$i<count($result);$i++) {
                if ($result[$i] == "?") {
                    $result[$i] = $bb;
                    break;
                }
            }
        }
        array_push($s, implode($result));
        $result = $input;
    }
    //var_dump($s);
    return $s;
}

function createSubstring($arr) {
    foreach($arr as $key => $val) { // get single chain
        for ($i=5; $i < strlen($val);$i++) { // get substring
            for ($offset=0; $offset < (strlen($val)-$i);$offset++) { // get offset
                $cc = substr($val, $offset, $i);
                echo $cc."<br>";
                if ($cc == strrev($cc)) {
                    return "IMPOSSIBLE";
                }
            }
        }
    }
    return "POSSIBLE";
}

/* Idee:
input:

z.B.
100???001

und dann ersetzen wir die ? mit einsen oder nullen:

100101001

Dann probieren wir jeden Substring, der größer als 5 ist.


Und drehen ihn jedes mal einmal um und vergleichen.



Das ganze passiert mit jeder Kombination von 1 und 0 in n ?.
--> string in Array konvertieren.
--> finde ? und speicher Positionen in Array
--> nehme Positionen und ersetze durch jede mögliche Reihenfolge.
*/