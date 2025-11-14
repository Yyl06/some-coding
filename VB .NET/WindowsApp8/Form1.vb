Public Class Form1
    Dim carPrices As New Dictionary(Of String, Decimal) From {
        {"Viva", 100D},
        {"MyVi", 150D},
        {"Alza", 170D},
        {"Saga", 120D},
        {"Persona", 150D}
    }

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        UpdateRentalList()
    End Sub
    Private Sub UpdateRentalList()
        lstRentalCars.Items.Clear()
        For Each car In carPrices.Keys
            lstRentalCars.Items.Add(car)
        Next
    End Sub


    ' Tab 1: Car Rental
    Private Sub btnCalculate_Click(sender As Object, e As EventArgs) Handles btnCalculate.Click
        If lstRentalCars.SelectedItem Is Nothing Then
            MessageBox.Show("Please select a car.")
            Exit Sub
        End If

        Dim days As Integer
        If Not Integer.TryParse(txtRentalDays.Text, days) OrElse days <= 0 Then
            MessageBox.Show("Please enter valid rental days.")
            Exit Sub
        End If

        Dim selectedCar As String = lstRentalCars.SelectedItem.ToString()
        Dim total As Decimal = carPrices(selectedCar) * days

        lblRentalResult.Text = "Total Amount: RM " & total.ToString("F2")
    End Sub


    ' Tab 2: Car Management
    Private Sub btnAddCar_Click(sender As Object, e As EventArgs) Handles btnAddCar.Click
        Dim newCar As String = txtNewCar.Text.Trim()
        Dim price As Decimal

        If newCar = "" Then
            MessageBox.Show("Enter a car name to add.")
            Exit Sub
        End If

        If Not Decimal.TryParse(txtNewPrice.Text, price) OrElse price <= 0 Then
            MessageBox.Show("Enter a valid rental price.")
            Exit Sub
        End If

        If carPrices.ContainsKey(newCar) Then
            MessageBox.Show("Car already exists.")
            Exit Sub
        End If

        carPrices.Add(newCar, price)
        lstManageCars.Items.Add(newCar)
        txtNewCar.Clear()
        txtNewPrice.Clear()

        UpdateRentalList()
    End Sub

    Private Sub btnDeleteCar_Click(sender As Object, e As EventArgs) Handles btnDeleteCar.Click
        If lstManageCars.SelectedItem IsNot Nothing Then
            Dim carToDelete As String = lstManageCars.SelectedItem.ToString()
            carPrices.Remove(carToDelete)
            lstManageCars.Items.Remove(carToDelete)

            UpdateRentalList()
        Else
            MessageBox.Show("Select a car to delete.")
        End If
    End Sub

    Private Sub btnCountCars_Click(sender As Object, e As EventArgs) Handles btnCountCars.Click
        MessageBox.Show("Total cars: " & lstManageCars.Items.Count)
    End Sub

    ' Tab 3: Number List
    Private Sub btnGenerate_Click(sender As Object, e As EventArgs) Handles btnGenerate.Click
        Dim num1, num2 As Integer

        If Not Integer.TryParse(txtNum1.Text, num1) OrElse Not Integer.TryParse(txtNum2.Text, num2) Then
            MessageBox.Show("Enter valid numbers.")
            Exit Sub
        End If

        lstNumbers.Items.Clear()

        If num1 < num2 Then
            For i As Integer = num1 To num2
                lstNumbers.Items.Add(i)
            Next
        Else
            For i As Integer = num1 To num2 Step -1
                lstNumbers.Items.Add(i)
            Next
        End If
    End Sub
End Class

