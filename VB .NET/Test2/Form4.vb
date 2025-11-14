Public Class Form4
    Private Sub btnCalculate_Click(sender As Object, e As EventArgs) Handles btnCalculate.Click
        Dim number As Double
        If Double.TryParse(txtPrice.Text, number) Then
            Dim total As Double = 0
            total = number - (number * 0.1)
            lblResult.Text = "Discounted Price(10%): " & total.ToString
        Else
            MessageBox.Show("Please Enter a valid Number!")
        End If
    End Sub
End Class