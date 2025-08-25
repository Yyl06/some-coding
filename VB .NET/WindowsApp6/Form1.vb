Namespace ShopInfo
    Module GlobalVars
        Public Const CoffeePrice As Double = 5.0
    End Module
End Namespace
Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Static CupsSold As Integer = 0
        CupsSold += 1
        Dim totalMoney As Double = CupsSold * ShopInfo.GlobalVars.CoffeePrice

        Label1.Text = "Total Cups Sold: " & CupsSold.ToString()
        Label2.Text = "Total Money Earned: RM" & totalMoney.ToString("0.00")
    End Sub
End Class