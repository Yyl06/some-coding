Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim Num1, Num2 As Integer
        Dim Largest, Smallest As Integer
        If Integer.TryParse(TextBox1.Text, Num1) AndAlso
            Integer.TryParse(TextBox2.Text, Num2) Then
            If Num1 > Num2 Then
                Largest = Num1
                Smallest = Num2
            ElseIf Num2 > Num1 Then
                Largest = Num2
                Smallest = Num1
            Else
                MessageBox.Show("Both numbers are equal.")
                Return
            End If
            MessageBox.Show("Largest Number: " & Largest.ToString() & vbCrLf &
                            "Smallest Number: " & Smallest.ToString())
        Else
            MessageBox.Show("Enter valid numbers for comparison.", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End If
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Dim Temp As Integer
        If Integer.TryParse(TextBox3.Text, Temp) Then
            If Temp > 30 Then
                MessageBox.Show("Hot")
            Else
                MessageBox.Show("Moderate")
            End If
        End If
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Dim Temp As Integer
        If Integer.TryParse(TextBox4.Text, Temp) Then
            If Temp >= 30 Then
                MessageBox.Show("Hot")
            ElseIf Temp < 20 Then
                MessageBox.Show("Cold")
            Else
                MessageBox.Show("Moderate")
            End If
        End If
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        Dim fishType As String = ComboBox1.SelectedItem
        Dim pricePerKg As Double
        Dim Weight As Double
        If Double.TryParse(TextBox7.Text, Weight) Then
            Select Case fishType
                Case "Kembung"
                    pricePerKg = 9.0

                Case "Kerisi"
                    pricePerKg = 10.0

                Case "Siakap"
                    pricePerKg = 12.0

                Case Else
                    MessageBox.Show("Please Select a Fish Type.")
                    Exit Sub
            End Select
            Dim totalPrice As Double = pricePerKg * Weight
            MessageBox.Show("Total Price: RM" & totalPrice.ToString("F2"))
        Else
            MessageBox.Show("Please enter a valid length.")
        End If
    End Sub
End Class
