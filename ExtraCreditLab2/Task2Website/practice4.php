<!DOCTYPE html>
<html>
<head>
    <title>Multiplication Table</title>
</head>
<body>
    <h2>Multiplication Table</h2>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Get the size of the multiplication table from the form
        $size = $_POST["size"];

        // Validate input: Check if $size is a positive integer
        if (!is_numeric($size) || $size <= 0 || floor($size) != $size) {
            echo "Please enter a positive integer.";
        } else {
            // Generate the multiplication table
            echo "<table border='1'>";
            echo "<tr><td></td>";
            for ($i = 1; $i <= $size; $i++) {
                echo "<td>$i</td>";
            }
            echo "</tr>";
            for ($i = 1; $i <= $size; $i++) {
                echo "<tr><td>$i</td>";
                for ($j = 1; $j <= $size; $j++) {
                    echo "<td>" . ($i * $j) . "</td>";
                }
                echo "</tr>";
            }
            echo "</table>";
        }
    }
    ?>
</body>
</html>
