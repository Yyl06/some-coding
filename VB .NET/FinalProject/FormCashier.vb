Imports System.IO
Public Class FormCashier
    'Constructor, runs when the form is opened
    Private Sub FormCashier_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        LvCart.View = View.Details
        LvCart.Columns.Add("Product", 150) '0
        LvCart.Columns.Add("Price", 80) '1
        LvCart.Columns.Add("Qty", 60) '2
        LvCart.Columns.Add("Subtotal", 80) '3
        cboPayment.Items.AddRange(New String() {"Cash", "Card", "E-Wallet"})
        cboPayment.SelectedIndex = 0
    End Sub
    Private Sub ClearInput()
        txtProductName.Clear()
        txtPrice.Clear()
        txtQuantity.Clear()
    End Sub
    '
    Private Sub UpdateTotals()
        Dim subtotal As Decimal = 0
        For Each item As ListViewItem In LvCart.Items
            subtotal += Decimal.Parse(item.SubItems(3).Text)
        Next

        Dim tax As Decimal = subtotal * 0.06D

        Dim discountPercent As Decimal = 0
        Decimal.TryParse(txtDiscount.Text, discountPercent)
        Dim discountAmt As Decimal = subtotal * (discountPercent / 100)

        Dim total As Decimal = subtotal + tax - discountAmt

        lblSubtotal.Text = $"Subtotal: RM {subtotal:0.00}" 'Equalavient = "Subtotal: RM " & subtotal.ToString("0.00")
        lblTax.Text = $"SST (6%): RM {tax:0.00}"
        lblTotal.Text = $"Total: RM {total:0.00}"
    End Sub
    Private Sub SaveTransaction()
        Dim folderPath As String = Application.StartupPath
        Dim filePath As String = Path.Combine(folderPath, "transactions.txt")

        Using sw As StreamWriter = File.AppendText(filePath)
            sw.WriteLine("===== TRANSACTION =====")
            sw.WriteLine("Date: " & DateTime.Now)
            For Each item As ListViewItem In LvCart.Items
                sw.WriteLine($"{item.Text} x{item.SubItems(2).Text} - RM {item.SubItems(3).Text}")
            Next
            sw.WriteLine(lblSubtotal.Text)
            sw.WriteLine(lblTax.Text)
            sw.WriteLine(lblTotal.Text)
            sw.WriteLine(lblChange.Text)
            sw.WriteLine("Payment: " & cboPayment.SelectedItem.ToString())
            sw.WriteLine("--------------------------")
        End Using
    End Sub
    Private Sub btnAdd_Click(sender As Object, e As EventArgs) Handles btnAdd.Click
        If txtProductName.Text = "" Or txtPrice.Text = "" Or txtQuantity.Text = "" Then
            MessageBox.Show("Please fill in all fields.")
            Exit Sub
        End If

        Dim name As String = txtProductName.Text
        Dim price As Decimal = Decimal.Parse(txtPrice.Text)
        Dim qty As Integer = Integer.Parse(txtQuantity.Text)
        Dim subtotal As Decimal = price * qty

        Dim item As New ListViewItem(name)
        item.SubItems.Add(price.ToString("0.00"))
        item.SubItems.Add(qty.ToString())
        item.SubItems.Add(subtotal.ToString("0.00"))
        LvCart.Items.Add(item)

        UpdateTotals()
        ClearInput()
    End Sub
    Private Sub btnPay_Click(sender As Object, e As EventArgs) Handles btnPay.Click
        If LvCart.Items.Count = 0 Then
            MessageBox.Show("Please add at least one item before payment.", "No Items", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            Exit Sub
        End If

        UpdateTotals()

        Dim total As Decimal
        Dim totalText As String = lblTotal.Text.Replace("Total: RM ", "").Trim()
        If Not Decimal.TryParse(totalText, total) Or total <= 0 Then
            MessageBox.Show("Invalid total amount.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
            Exit Sub
        End If

        Dim method As String = cboPayment.SelectedItem.ToString()
        If method = "Cash" Then
            Dim cash As Decimal
            If Not Decimal.TryParse(txtCash.Text.Trim(), cash) Then
                MessageBox.Show("Please enter a valid cash amount.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
                Exit Sub
            End If

            Dim change As Decimal = cash - total
            If change < 0 Then
                MessageBox.Show("Insufficient payment!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
                Exit Sub
            End If
            lblChange.Text = "Change: RM " & change.ToString("0.00")
        Else
            lblChange.Text = "Payment via " & method & " successful."
        End If

        SaveTransaction()
        MessageBox.Show("Payment successful!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information)
    End Sub
    Private Sub btnPrint_Click(sender As Object, e As EventArgs) Handles btnPrint.Click
        Dim receipt As String =
            "===== SUPERMARKET RECEIPT =====" & vbCrLf &
            "Date: " & DateTime.Now.ToString() & vbCrLf &
            "--------------------------------" & vbCrLf

        For Each item As ListViewItem In LvCart.Items
            receipt &= $"{item.Text} x{item.SubItems(2).Text} - RM {item.SubItems(3).Text}" & vbCrLf
        Next

        receipt &= "--------------------------------" & vbCrLf &
            lblSubtotal.Text & vbCrLf &
            lblTax.Text & vbCrLf &
            lblTotal.Text & vbCrLf &
            lblChange.Text & vbCrLf &
            "Payment Method: " & cboPayment.SelectedItem.ToString() & vbCrLf &
            "Thank you! Come again!" & vbCrLf

        Dim folderPath As String = Application.StartupPath '.exe files locates
        Dim filePath As String = Path.Combine(folderPath, $"receipt_{DateTime.Now:yyyyMMdd_HHmmss}.txt")

        File.WriteAllText(filePath, receipt)
        MessageBox.Show($"Receipt saved as {Path.GetFileName(filePath)} ", "Receipt")

        If File.Exists(filePath) Then
            Process.Start("C:\Windows\System32\notepad.exe", filePath)
        End If
    End Sub
    Private Sub btnSearch_Click(sender As Object, e As EventArgs) Handles btnSearch.Click
        For Each item As ListViewItem In LvCart.Items
            item.Selected = item.Text.ToLower().Contains(txtSearch.Text.ToLower())
        Next
    End Sub
    Private Sub btnClear_Click(sender As Object, e As EventArgs) Handles btnClear.Click
        LvCart.Items.Clear()
        lblSubtotal.Text = "Subtotal: RM 0.00"
        lblTax.Text = "Tax (6%): RM 0.00"
        lblTotal.Text = "Total: RM 0.00"
        lblChange.Text = "Change:"
        txtCash.Clear()
    End Sub
    Private Sub btnRemove_Click(sender As Object, e As EventArgs) Handles btnRemove.Click
        If LvCart.SelectedItems.Count > 0 Then
            For Each item As ListViewItem In LvCart.SelectedItems
                LvCart.Items.Remove(item)
            Next
            UpdateTotals()
        Else
            MessageBox.Show("Please select an item to remove.")
        End If
    End Sub
    Private Sub btnBack_Click(sender As Object, e As EventArgs) Handles btnBack.Click
        Me.Hide()
        MainUI.Show()
    End Sub

    Private Sub btnLogout_Click(sender As Object, e As EventArgs) Handles btnLogout.Click
        Dim result As DialogResult = MessageBox.Show("Logout from system?", "Confirm Logout", MessageBoxButtons.YesNo, MessageBoxIcon.Question)
        If result = DialogResult.Yes Then
            Me.Hide()
            Login.txtUser.Clear()
            Login.txtPass.Clear()
            Login.lblMessage.Text = ""
            Login.Show()
        End If
    End Sub
End Class