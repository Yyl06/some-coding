Public Class Form1
    Private Sub Calc_click(sender As Object, e As EventArgs) Handles ButtonCalculate.Click
        Dim total As Decimal = 0D
        Dim baseFare As Decimal = 0D
        Dim passengerCount As Integer

        If Not Decimal.TryParse(TextBoxNOPassenger.Text, passengerCount) OrElse passengerCount <= 0 Then
            MessageBox.Show("Please enter a valid number of passengers.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            Return
        End If

        If Not RadioButtonSenaiKul.Checked AndAlso Not RadioButtonSenaiKuc.Checked Then
            MessageBox.Show("Please select a valid route.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            Return
        End If

        If Not RadioButtonOneWay.Checked AndAlso Not RadioButtonTwoWay.Checked Then
            MessageBox.Show("Please select a valid trip type.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            Return
        End If

        If RadioButtonSenaiKul.Checked Then
            baseFare = 100D
        ElseIf RadioButtonSenaiKuc.Checked Then
            baseFare = 200D
        End If

        If RadioButtonOneWay.Checked Then
            total = baseFare * passengerCount
        ElseIf RadioButtonTwoWay.Checked Then
            total = (baseFare * passengerCount) * 2
        End If

        LabelTotal.Text = "Total Price: RM " & total.ToString("C2")
    End Sub
End Class
