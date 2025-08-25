Public Class Form1
    Dim customerCount As Integer = 0
    Dim totalSales As Double = 0.0
    Private Sub CalculatePriceToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles CalculatePriceToolStripMenuItem.Click
        Dim total As Double = 0.00

        If CheckBoxKembung.Checked Then
            Dim weightKembung As Double = Val(TextBoxKembung.Text)
            Dim priceKembung As Double = 9.0
            If CheckBoxCleanKembung.Checked Then
                priceKembung += 1.0
            End If
            total += weightKembung * priceKembung
        End If

        If CheckBoxKerisi.Checked Then
            Dim weightKerisi As Double = Val(TextBoxKerisi.Text)
            Dim priceKerisi As Double = 10.0
            If CheckBoxCleanKerisi.Checked Then
                priceKerisi += 1.0
            End If
            total += weightKerisi * priceKerisi
        End If

        If CheckBoxSiakap.Checked Then
            Dim weightSiakap As Double = Val(TextBoxSiakap.Text)
            Dim priceSiakap As Double = 12.0
            If CheckBoxCleanSiakap.Checked Then
                priceSiakap += 1.0
            End If
            total += weightSiakap * priceSiakap
        End If

        MessageBox.Show("Total Price: RM " & total.ToString("F2"), "Price Calculation", MessageBoxButtons.OK, MessageBoxIcon.Information)
        customerCount += 1
        totalSales += total
    End Sub

    Private Sub ViewSummaryToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ViewSummaryToolStripMenuItem.Click
        Dim summary As New SummaryForm

        summary.ShowCustomers.Text = customerCount.ToString()
        summary.ShowSales.Text = totalSales.ToString("F2")
        If customerCount > 0 Then
            summary.ShowAverage.Text = totalSales / customerCount.ToString("F2")
        Else
            summary.ShowAverage.Text = "0.00"
        End If
        summary.Show()
    End Sub

    Private Sub NextCustomerToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles NextCustomerToolStripMenuItem.Click
        TextBoxKembung.Text = ""
        TextBoxKerisi.Text = ""
        TextBoxSiakap.Text = ""

        CheckBoxKembung.Checked = False
        CheckBoxKerisi.Checked = False
        CheckBoxSiakap.Checked = False

        CheckBoxCleanKembung.Checked = False
        CheckBoxCleanKerisi.Checked = False
        CheckBoxCleanSiakap.Checked = False
    End Sub
    Private Sub ExitToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ExitToolStripMenuItem.Click
        Application.Exit()
    End Sub

    Private Sub AboutToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles AboutToolStripMenuItem.Click
        MessageBox.Show("Fish Price Calculator System" & vbCrLf &
                    "Developed by Group 6" & vbCrLf &
                    "This application allows users to calculate fish prices based on selected types, weight, and cleaning options." & vbCrLf &
                    "It includes menu-based navigation and a sales summary report for multiple customers.", "About")
    End Sub
End Class