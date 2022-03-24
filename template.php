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

$manual_input="4
1 9
91 99
451 460
501 1000";
main();

function main() {
    global $numberOfCases, $cases;
    input();
    foreach ($cases as $case) { // Cases
        $a = $case[0];
        $b = $case[1];
        // Write your code here:


        $result = $a + $b;

        printCase($result);
    }
}
