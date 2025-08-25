Public Class Form1
    Dim firstNum As Double = 0
    Dim secondNum As Double = 0
    Dim operation As String = ""
    Dim isOperationClicked As Boolean = False
    Private Sub Button_Click(sender As Object, e As EventArgs) Handles ButtonDot.Click, Button0.Click, Button1.Click, Button2.Click, Button3.Click, Button4.Click, Button5.Click, Button6.Click, Button7.Click, Button8.Click, Button9.Click
        Dim button As Button = CType(sender, Button)
        Dim input As String = button.Text

        If TextBox1.Text = "0" OrElse isOperationClicked Then
            If input = "." Then
                TextBox1.Text = "0."
            Else
                TextBox1.Text = input
            End If
        Else
            If input = "." AndAlso TextBox1.Text.Contains(".") Then
                Return
            End If
            TextBox1.Text &= input
        End If
        isOperationClicked = False
    End Sub

    Private Sub Operator_Click(sender As Object, e As EventArgs) Handles ButtonPlus.Click, ButtonMinus.Click, ButtonMul.Click, ButtonDiv.Click
        Dim button As Button = CType(sender, Button)
        firstNum = Val(TextBox1.Text)
        operation = button.Text
        isOperationClicked = True

        Label1.Text = firstNum.ToString() & operation
    End Sub

    Private Sub ButtonEqual_Click(sender As Object, e As EventArgs) Handles ButtonEqual.Click
        secondNum = Val(TextBox1.Text)
        Dim result As Double = 0

        Select Case operation
            Case "+"
                result = firstNum + secondNum
            Case "-"
                result = firstNum - secondNum
            Case "×", "x", "*"
                result = firstNum * secondNum
            Case "/", "÷"
                If secondNum = 0 Then
                    TextBox1.Text = "Error"
                    Label1.Text = ""
                    Exit Sub
                Else
                    result = firstNum / secondNum
                End If
        End Select
        TextBox1.Text = result.ToString()
        Label1.Text = ""

        firstNum = result
        operation = ""
        isOperationClicked = True
    End Sub

    Private Sub ButtonClear_Click(sender As Object, e As EventArgs) Handles ButtonClear.Click
        TextBox1.Text = ""
        Label1.Text = ""
    End Sub

    Private Sub ButtonBackspace_Click(sender As Object, e As EventArgs) Handles ButtonBackspace.Click
        If TextBox1.Text.Length > 1 Then
            TextBox1.Text = TextBox1.Text.Substring(0, TextBox1.Text.Length - 1)
        Else
            TextBox1.Text = "0"
        End If
    End Sub

    Private Sub ButtonSqrt_Click(sender As Object, e As EventArgs) Handles ButtonSqrt.Click
        Dim number As Double = Val(TextBox1.Text)
        If number < 0 Then
            TextBox1.Text = "Error"
        Else
            TextBox1.Text = Math.Sqrt(number).ToString()
        End If
    End Sub

    Private Sub ButtonInverse_Click(sender As Object, e As EventArgs) Handles ButtonInverse.Click
        Dim number As Double = Val(TextBox1.Text)
        If number <> 0 Then
            TextBox1.Text = (1 / number).ToString()
        Else
            TextBox1.Text = "Error"
        End If
    End Sub

    Private Sub SignToggle_Click(sender As Object, e As EventArgs) Handles ButtonPlusMinus.Click
        Dim number As Double = Val(TextBox1.Text)
        TextBox1.Text = (-number).ToString()
    End Sub

    Private Sub ButtonPercent_Click(sender As Object, e As EventArgs) Handles ButtonPercent.Click
        Dim number As Double = Val(TextBox1.Text)
        TextBox1.Text = (number / 100).ToString()
    End Sub

    Private Sub ButtonCE_Click(sender As Object, e As EventArgs) Handles ButtonCE.Click
        TextBox1.Text = ""
        firstNum = 0
        secondNum = 0
        operation = ""
        isOperationClicked = False
        Label1.Text = ""
    End Sub

    Private Sub ButtonSquare_Click(sender As Object, e As EventArgs) Handles ButtonPwSq.Click
        Dim number As Double = Val(TextBox1.Text)
        TextBox1.Text = Math.Pow(number, 2).ToString()
    End Sub
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        TextBox1.Text = "0"
    End Sub
End Class
